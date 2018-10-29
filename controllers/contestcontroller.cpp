#include "contestcontroller.h"
#include "contest.h"

/* Contest / Contests Collection / List All Contests
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/contests-collection/list-all-contests
 *
 */
void ContestController::list()
{
    renderJson(Contest::getAllJson());
}

/* Contest / Contest / View a Contest Detail
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/contest/view-a-contest-detail
 *
 */
void ContestController::details(const QString &contestId)
{
    auto contest = Contest::get(contestId.toInt());
    auto contest_qvarmap = contest.toVariantMap();
    contest_qvarmap.erase(contest_qvarmap.find("lockRevision"));

    renderJson(contest_qvarmap);
}

/* Contest / Contests Collection / Create Contes
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/contests-collection/create-contest
 *
 */
void ContestController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto contest = httpRequest().formItems("contest");
        auto model = Contest::create(contest);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.contestId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(contest);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

/* Contest / Contest / Edit a Contest
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/contest/edit-a-contest
 *
 */
void ContestController::edit(const QString &contestId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Contest::get(contestId.toInt());
        if (!model.isNull()) {
            session().insert("contest_lockRevision", model.lockRevision());
            auto contest = model.toVariantMap();
            texport(contest);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("contest_lockRevision").toInt();
        auto model = Contest::get(contestId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", contestId));
            break;
        }

        auto contest = httpRequest().formItems("contest");
        model.setProperties(contest);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.contestId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(contest);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

/* Contest / Contest / Leave Contest
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/contest/leave-contest
 *
 */
void ContestController::leave(const QString &contestId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto contest = Contest::get(contestId.toInt());
    contest.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ContestController)
