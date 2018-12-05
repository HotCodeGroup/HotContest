#include <TPaginator>
#include "submitcontroller.h"
#include "submit.h"

#include "testsubmit.h"

int SubmitController::testsLimit = 5;
int SubmitController::items_per_page = 8;
int SubmitController::show_around = 5;

/* Contest / Submits Collection / View a submit list
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/submit/view-a-submit-details
 *
 */
void SubmitController::list(const QString &contestId)
{
    bool ok = false;
    int contestIntId = contestId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonObject());
    }

    int current = httpRequest().queryItemValue("page", "1").toInt(&ok);
    if (!ok) {
        current = 1;
    }

    int problemId = httpRequest().queryItemValue("problem", "").toInt(&ok);
    if (!ok) {
        problemId = 0;
    }


    int total = Submit::countUserContestSubmits(contestIntId, 1, problemId);
    TPaginator pager(total, SubmitController::items_per_page, SubmitController::show_around);
    pager.setCurrentPage(current);

    //Позже userId будет браться из аналога Cookies
    renderJson(Submit::getUserContestSubmitsJson(contestIntId, 1, pager.itemCountPerPage(), pager.offset(), problemId));
}

/* Contest / Submit / View a submit details
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/scores/view-a-scoreboard
 *
 */
void SubmitController::details(const QString &contestId, const QString &submitId)
{
    bool ok = false;
    contestId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonObject());
    }

    int submitIntID = submitId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonObject());
    }

    auto submitFullInfo = Submit::getFullInfo(submitIntID, testsLimit);
    renderJson(submitFullInfo);
}


// Don't remove below this line
T_DEFINE_CONTROLLER(SubmitController)