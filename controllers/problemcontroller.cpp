#include "problemcontroller.h"
#include "problem.h"

/* Contest / Problems Collection / View a problems collection
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/problems-collection/view-a-problems-collection
 *
 */
void ProblemController::list(const QString &contestId)
{
    bool ok = false;
    int contestIntID = contestId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonArray());
    }

    //ID юзера будет браться из аналога Cookies
    renderJson(Problem::getShortAllJson(1, contestIntID));
}

/* Contest / Problem / View a Problem Detail
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/problem/view-a-problem-detail
 *
 */
void ProblemController::details(const QString &contestId, const QString &problemId)
{
    //Params validation
    bool ok = false;
    int contestIntID = contestId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonObject());
    }
    int problemIntID = problemId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonObject());
    }

    auto problemVariantMap = Problem::getWithContest(contestIntID, problemIntID).toVariantMapLight();
    if (problemVariantMap["problemId"] == 0) {
        renderJson(QJsonObject());
    }

    renderJson(problemVariantMap);
}

/* Contest / Problems Collection / Create Problem
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/problems-collection/create-problem
 *
 */
void ProblemController::create(const QString &contestId)
{
//    switch (httpRequest().method()) {
//    case Tf::Get:
//        render();
//        break;
//
//    case Tf::Post: {
//        auto problem = httpRequest().formItems("problem");
//        auto model = Problem::create(problem);
//
//        if (!model.isNull()) {
//            QString notice = "Created successfully.";
//            tflash(notice);
//            redirect(urla("show", model.problemId()));
//        } else {
//            QString error = "Failed to create.";
//            texport(error);
//            texport(problem);
//            render();
//        }
//        break; }
//
//    default:
//        renderErrorResponse(Tf::NotFound);
//        break;
//    }
}

/* Contest / Problem / Edit a Problem
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/problem/edit-a-problem
 *
 */
void ProblemController::edit(const QString &contestId, const QString &problemId)
{
//    switch (httpRequest().method()) {
//    case Tf::Get: {
//        auto model = Problem::get(problemId.toInt());
//        if (!model.isNull()) {
//            session().insert("problem_lockRevision", model.lockRevision());
//            auto problem = model.toVariantMap();
//            texport(problem);
//            render();
//        }
//        break; }
//
//    case Tf::Post: {
//        QString error;
//        int rev = session().value("problem_lockRevision").toInt();
//        auto model = Problem::get(problemId.toInt(), rev);
//
//        if (model.isNull()) {
//            error = "Original data not found. It may have been updated/removed by another transaction.";
//            tflash(error);
//            redirect(urla("save", problemId));
//            break;
//        }
//
//        auto problem = httpRequest().formItems("problem");
//        model.setProperties(problem);
//        if (model.save()) {
//            QString notice = "Updated successfully.";
//            tflash(notice);
//            redirect(urla("show", model.problemId()));
//        } else {
//            error = "Failed to update.";
//            texport(error);
//            texport(problem);
//            render();
//        }
//        break; }
//
//    default:
//        renderErrorResponse(Tf::NotFound);
//        break;
//    }
}

/* Contest / Problem / Remove Problem
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/problem/remove-problem
 *
 */
void ProblemController::remove(const QString &contestId, const QString &problemId)
{
//    if (httpRequest().method() != Tf::Post) {
//        renderErrorResponse(Tf::NotFound);
//        return;
//    }
//
//    auto problem = Problem::get(problemId.toInt());
//    problem.remove();
//    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ProblemController)
