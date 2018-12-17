#include <vector>
#include <string>

class Tester {
public:
    enum test_res {
        OK,
        WA,
        CE,
        TL,
        ML,
        RE
    };

    Tester(unsigned long max_time,
           unsigned long max_memory,
           std::string &test_file_path,
           std::string &root_dir_path,
           std::string &root_env_path,
           std::string &root_backup_dir_path,
           std::vector<std::string> &test_inputs_paths,
           std::vector<std::string> &test_outputs_paths);;

    void addTest(std::string &test_input_path, std::string &test_output_path);;
    int getProcessPid(int paretnt_pid, std::string proc_name);
    bool timeUsageInLimits(int pid);

    bool memoryUsageInLimits(int pid) {
        return true;
    }

    std::vector<enum test_res> runCPPSimpleTests();
    enum test_res runCPPSimpleTest(std::string &test_input_path, std::string &test_output_path);;
    enum test_res checkCPPSimpleTestRes(std::string &test_output_path, std::string &res_path);
    void prepareData(std::string &test_input_path);
private:
    unsigned long max_time;
    unsigned long max_memory;
    std::string test_file_path;
    std::string root_dir_path;
    std::string root_env_path;
    std::string root_backup_dir_path;
    std::vector<std::string> test_inputs_paths;
    std::vector<std::string> test_outputs_paths;
    const std::string test_prog_name = "test_prog.cpp";

    static inline bool space(char c);

    static inline bool notspace(char c);

//break a sentence into words
    static std::vector<std::string> split(const std::string &s);
    static std::string exec(std::string &cmd, bool ret = true);
    static bool file_exist(const std::string &name);
};