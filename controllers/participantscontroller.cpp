#include "participantscontroller.h"
#include "contest.h"

/* Contest / Participants / View a participants list
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/participants/view-a-participants-list
 *
 */
void ParticipantsController::list(const QString &contestId)
{
    auto contest = Contest::get(contestId.toInt());
    auto contest_qvarmap = contest.toVariantMap();
    // contest_qvarmap.erase(contest_qvarmap.find("lockRevision"));

    renderJson(contest_qvarmap);
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ParticipantsController)
