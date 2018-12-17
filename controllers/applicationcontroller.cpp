#include "applicationcontroller.h"
#include "submit.h"

boost::fibers::buffered_channel<testInfo> ApplicationController::task_channel{1024};

ApplicationController::ApplicationController()
    : TActionController()
{ }

ApplicationController::~ApplicationController()
{ }

/* HotContest API Root / Retrieve the Entry Point
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#introduction/description-of-usual-server-responses:
 * 
 */ 
void ApplicationController::index()
{
    QVariantMap commands;
    commands["contestsURL"] = "/contests";
    commands["usersURL"] = "/users";

    renderJson(commands);
}

void ApplicationController::staticInitialize()
{ 
    qDebug() << "INIT";
    
    // boost::fibers::buffered_channel<task> ch{1024};
    auto worker = std::thread(
        [&task_channel]{
            testInfo tsk;
            qDebug() << "WAIT FOR TASKS";
            // dequeue and process tasks
            while (boost::fibers::channel_op_status::closed!=task_channel.pop(tsk)){
                qDebug() << "TASK";
                std::string test_file_path = tsk[0].toStdString();
                std::string root_dir_path = "/var/chroot/xenial";
                std::string root_env_path = "CPP";
                std::string root_backup_dir_path = "Not supported yet";
                int testNumber = tsk[3].toInt();
                std::vector<std::string> test_inputs_paths(testNumber);
                std::vector<std::string> test_outputs_paths(testNumber);
                for (int i = 0; i < testNumber; i++) {
                    test_inputs_paths[i] = (tsk[1] + "in" + QString::number(i+1) + ".txt").toStdString();
                    test_outputs_paths[i] = (tsk[2] + "out" + QString::number(i+1) + ".txt").toStdString();
                }

                Tester tester(tsk[4].toInt(), tsk[5].toInt(), test_file_path, root_dir_path, root_env_path, root_backup_dir_path, test_inputs_paths,
                              test_outputs_paths);

                std::vector<Tester::test_res> res = tester.runCPPSimpleTests();

                if (res[res.size() - 1] != Tester::OK) {
                    qDebug() << "WA";
                } else {
                    qDebug() << "OK";
                }
            }
        });
    worker.detach();
}

void ApplicationController::staticRelease()
{ }

bool ApplicationController::preFilter()
{
    return true;
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApplicationController)
