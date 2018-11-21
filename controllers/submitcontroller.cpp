#include "submitcontroller.h"
#include "submit.h"

/* Contest / Submits Collection / View a submit list
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/submit/view-a-submit-details
 *
 */
void SubmitController::list(const QString &contestId)
{
    auto submitList = Submit::getAll();
    texport(submitList);
    render();
}

/* Contest / Submit / View a submit details
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/scores/view-a-scoreboard
 *
 */
void SubmitController::details(const QString &contestId, const QString &submitId)
{
//    bool ok = false;
//    contestId.toInt(&ok);
//    if (!ok) {
//        renderJson(QJsonObject());
//    }
//
//    int submitIntID = submitId.toInt(&ok);
//    if (!ok) {
//        renderJson(QJsonObject());
//    }
//
//    int current = httpRequest().queryItemValue("page", "1").toInt(&ok);
//    if (!ok) {
//        current = 1;
//    }
//    int total = Contest::countPublic();
//    TPaginator pager(total, ContestController::items_per_page, ContestController::show_around);
//    pager.setCurrentPage(current);
//
//    renderJson(Contest::getJsonList(pager.itemCountPerPage(), pager.offset()));
//
//    auto submitFullInfo = Submit::getFullInfo(submitIntID);
//    renderJson(submitFullInfo);
}


// Don't remove below this line
T_DEFINE_CONTROLLER(SubmitController)