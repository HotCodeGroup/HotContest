#include "contestcontroller.h"
#include "contest.h"


void ContestController::index()
{
    auto contestList = Contest::getAll();
    texport(contestList);
    render();
}

void ContestController::show(const QString &contestId)
{
    auto contest = Contest::get(contestId.toInt());
    texport(contest);
    render();
}

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

void ContestController::save(const QString &contestId)
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

void ContestController::remove(const QString &contestId)
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
