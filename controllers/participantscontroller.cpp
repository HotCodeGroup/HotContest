#include "participantscontroller.h"
#include "contest.h"
#include <TPaginator>

int ParticipantsController::items_per_page = 10;
int ParticipantsController::show_around = 5;

/* Contest / Participants / View a participants list
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/participants/view-a-participants-list
 *
 */
void ParticipantsController::list(const QString &contestId)
{
    bool ok = false;
    int contestIntID = contestId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonArray());
    }
    auto contest = Contest::get(contestIntID);

    int current = httpRequest().queryItemValue("page", "1").toInt(&ok);
    if (!ok) {
        current = 1;
    }
    int total = Contest::countPublic();
    TPaginator pager(total, ParticipantsController::items_per_page, ParticipantsController::show_around);
    pager.setCurrentPage(current);

    renderJson(QJsonArray::fromStringList(contest.participants(pager.itemCountPerPage(), pager.offset())));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ParticipantsController)
