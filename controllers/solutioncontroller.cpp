#include "solutioncontroller.h"
#include "solution.h"


void SolutionController::index()
{
    auto solutionList = Solution::getAll();
    texport(solutionList);
    render();
}

void SolutionController::show(const QString &solutionId)
{
    auto solution = Solution::get(solutionId.toInt());
    texport(solution);
    render();
}

void SolutionController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto solution = httpRequest().formItems("solution");
        auto model = Solution::create(solution);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.solutionId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(solution);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void SolutionController::save(const QString &solutionId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Solution::get(solutionId.toInt());
        if (!model.isNull()) {
            session().insert("solution_lockRevision", model.lockRevision());
            auto solution = model.toVariantMap();
            texport(solution);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("solution_lockRevision").toInt();
        auto model = Solution::get(solutionId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", solutionId));
            break;
        }

        auto solution = httpRequest().formItems("solution");
        model.setProperties(solution);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.solutionId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(solution);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void SolutionController::remove(const QString &solutionId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto solution = Solution::get(solutionId.toInt());
    solution.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(SolutionController)
