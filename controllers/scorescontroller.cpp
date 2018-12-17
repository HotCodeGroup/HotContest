#include "scorescontroller.h"
#include "contest.h"

/* Contest / Scores / View a scoreboard
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/scores/view-a-scoreboard
 *
 */
void ScoresController::list(const QString &contestId)
{
    auto contest = Contest::get(contestId.toInt());
    auto contest_qvarmap = contest.toVariantMap();
    // contest_qvarmap.erase(contest_qvarmap.find("lockRevision"));

    renderJson(contest_qvarmap);
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ScoresController)
