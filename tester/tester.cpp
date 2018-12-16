#include <experimental/filesystem>
#include <unistd.h>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <signal.h>
#include <wait.h>
#include <algorithm>
#include <iostream>
#include "tester.h"

Tester::Tester(unsigned long max_time, unsigned long max_memory, std::string &test_file_path,
               std::string &root_dir_path, std::string &root_env_path, std::string &root_backup_dir_path,
               std::vector<std::string> &test_inputs_paths, std::vector<std::string> &test_outputs_paths) : max_time(max_time), max_memory(max_memory),
                                                                                                            test_file_path(test_file_path), root_dir_path(root_dir_path),
                                                                                                            root_env_path(root_env_path),
                                                                                                            root_backup_dir_path(root_backup_dir_path),
                                                                                                            test_inputs_paths(test_inputs_paths),
                                                                                                            test_outputs_paths(test_outputs_paths) {}

void Tester::addTest(std::string &test_input_path, std::string &test_output_path) {
    test_inputs_paths.push_back(test_input_path);
    test_outputs_paths.push_back(test_output_path);
}

int Tester::getProcessPid(int paretnt_pid, std::string proc_name) {
    std::string pstree_cmd = "pstree -p " + std::to_string(paretnt_pid);
    std::string proc_tree = exec(pstree_cmd);
    unsigned long pos = proc_tree.find(proc_name);
    if (pos == std::string::npos) {
        return -1;
    }
    std::string proc_info = proc_tree.substr(pos);
    return std::stoi(proc_info.substr(proc_info.find('(') + 1, proc_info.find(')') - 1));
}

bool Tester::timeUsageInLimits(int pid) {
    std::string stat_cmd = "cat /proc/" + std::to_string(pid) + "/stat";
    std::string cat_res = exec(stat_cmd);

    std::cout << cat_res << std::endl;
    if (cat_res[0] == 'c')
        return true;
    std::vector<std::string> info = split(cat_res);
    std::cout << "INFO: " << info[13] << ' ' << info[14] << ' ' << info[15] << ' ' << info[16] << ' ' << info[21] << std::endl;

    unsigned long total_time = std::stoul(info[13]) + std::stoul(info[14]) + std::stoul(info[15]) + std::stoul(info[16]);
    long hertz = sysconf(_SC_CLK_TCK);
    double passed_time = (double)total_time / hertz;
    std::cout << "TIME: "<< passed_time << std::endl;

    return passed_time * 1000 < max_time;
}

std::vector<Tester::test_res> Tester::runCPPSimpleTests() {
    std::vector<enum test_res> res;
    for (size_t i = 0; i < test_inputs_paths.size(); i++) {
        res.emplace_back(runCPPSimpleTest(test_inputs_paths[i], test_outputs_paths[i]));
    }
    return res;
}

Tester::test_res Tester::runCPPSimpleTest(std::string &test_input_path, std::string &test_output_path) {
    prepareData(test_input_path);
    test_res res = OK;
    int proc = fork();
    if (proc != 0) {
        std::cout << "my son is: " << proc << std::endl;

        while (true) {
            int status;
            pid_t result = waitpid(proc, &status, WNOHANG);
            if (result == 0) {
                int test_pid = getProcessPid(proc, "inf");
                if (test_pid != -1) {
                    std::string kill_cmd = "kill -9 " + std::to_string(test_pid);
                    if (!timeUsageInLimits(test_pid)) {
                        res = TL;
                        exec(kill_cmd);
                    }
                    if (!memoryUsageInLimits(test_pid)) {
                        res = ML;
                        exec(kill_cmd);
                    }
                }
            } else if (result == -1) {
                // Error
                kill(proc, 0);
                throw std::runtime_error("somthing wrong with child procces");
            } else {
                // Child exited
                std::string path_to_res = root_dir_path + "/" + root_env_path + "/out.txt";
                if(res != OK){
                    return res;
                }
                return checkCPPSimpleTestRes(test_output_path, path_to_res);
            }
        }
    } else {
        std::cout << "wow i've been born" << std::endl;
        std::string run_test_cmd =
                "chroot " + root_dir_path + " /bin/bash -c \"" + "cd " + root_env_path +
                " && g++ " + test_prog_name +
                " -o inf 2> comp_err.txt && (./inf < in.txt > out.txt 2> err.txt )\"";
        system(run_test_cmd.c_str());
        std::cout << "inf stopped" << std::endl;
        exit(0);
    }
}

Tester::test_res Tester::checkCPPSimpleTestRes(std::string &test_output_path, std::string &res_path) {
    std::cout << "checking res" << std::endl;
    std::string path_to_comp_error = root_dir_path + "/" + root_env_path + "/comp_err.txt";
    std::string path_to_output = root_dir_path + "/" + root_env_path + "/out.txt";
    std::string path_to_error = root_dir_path + "/" + root_env_path + "/err.txt";
    if (file_exist(path_to_comp_error)) {
        std::ifstream t(path_to_comp_error);
        std::string str((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());
        if (!str.empty()) {
            return CE;
        }
        t.close();
    } else {
        throw "some nasty shit happens comp_err.txt does not exist";
    }
    if (file_exist(path_to_error)) {
        std::ifstream t(path_to_error);
        std::string str((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());
        if (!str.empty()) {
            return RE;
        }
        t.close();
    } else {
        throw "some nasty shit happens err.txt does not exist";
    }
    std::string diff_cmd = "diff -w -B " + path_to_output + " " + test_output_path;
    std::string diff_res = exec(diff_cmd);
    if (diff_res.empty()) {
        return OK;
    } else {
        return WA;
    }
}

void Tester::prepareData(std::string &test_input_path) {
    /*std::string prepare_workspace_cmd = "cp -R " + root_backup_dir_path + " " + root_dir_path;
    exec(prepare_workspace_cmd);*/ // TODO: create correct using of backup files
    std::string copy_test_file_cmd = "cp " + test_file_path + " " + root_dir_path + "/" + root_env_path;
    exec(copy_test_file_cmd);
    std::string copy_input_file_cmd = "cp " + test_input_path + " " + root_dir_path + "/" + root_env_path;
    exec(copy_input_file_cmd);
    std::string test_file_name = test_file_path.substr(test_file_path.rfind('/') == std::string::npos
                                                       ? 0 : (test_file_path.rfind('/') + 1));
    std::string rename_test_file =
            "mv " + root_dir_path + "/" + root_env_path + "/" + test_file_name + " " +
            root_dir_path + "/" + root_env_path + "/" + test_prog_name;
    exec(rename_test_file);

    std::string input_file_name = test_input_path.substr(test_input_path.rfind('/') == std::string::npos
                                                         ? 0 : (test_input_path.rfind('/') + 1));
    std::string rename_input_file =
            "mv " + root_dir_path + "/" + root_env_path + "/" + input_file_name + " " +
            root_dir_path + "/" + root_env_path + "/in.txt";
    exec(rename_input_file);

}

bool Tester::space(char c) {
    return std::isspace(c);
}

bool Tester::notspace(char c) {
    return !std::isspace(c);
}

std::vector<std::string> Tester::split(const std::string &s) {
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter i = s.begin();
    while (i != s.end()) {
        i = std::find_if(i, s.end(), notspace); // find the beginning of a word
        iter j = std::find_if(i, s.end(), space); // find the end of the same word
        if (i != s.end()) {
            ret.emplace_back(std::string(i, j)); //insert the word into vector
            i = j; // repeat 1,2,3 on the rest of the line.
        }
    }
    return ret;
}

std::string Tester::exec(std::string &cmd, bool ret) {
    std::array<char, 128> buf;
    std::string res;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    if (ret) {
        while (fgets(buf.data(), buf.size(), pipe.get()) != nullptr) {
            res += buf.data();
        }
        return res;
    }
    return "";
}

bool Tester::file_exist(const std::string &name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

