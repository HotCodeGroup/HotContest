#include "solutioncontroller.h"
#include "solution.h"
#include "submit.h"

/* Contest / Solution / Send solution
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/solution/send-solution
 *
 */
void SolutionController::send(const QString &contestId, const QString &problemPos)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::MethodNotAllowed);
        return;
    }

    bool ok = false;
    int contestIntID = contestId.toInt(&ok);
    if (!ok) {
        renderErrorResponse(Tf::BadRequest);
        return;
    }

    int problemIntPos = problemPos.toInt(&ok);
    if (!ok) {
        renderErrorResponse(Tf::BadRequest);
        return;
    }

    TMultipartFormData &formdata = httpRequest().multipartFormData();
    auto model = Solution::create(formdata, 1, contestIntID, problemIntPos);
    if (model.isNull()) {
        renderErrorResponse(Tf::ServiceUnavailable);
        return;
    }

    testInfo tests = {
        model.srcFile(),
        "/home/gdvfox/StudyMaterials/CPP_Programming/HotContestData/tests/" + contestId + "/" + problemPos + "/in/",
        "/home/gdvfox/StudyMaterials/CPP_Programming/HotContestData/tests/" + contestId + "/" + problemPos + "/out/",
        "50",
        "10000",
        "2000000",
        QString::number(model.solutionId()),
    };
    ApplicationController::task_channel.push(tests);

    renderErrorResponse(Tf::Created);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(SolutionController)
