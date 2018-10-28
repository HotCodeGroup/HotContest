#include "problemcontroller.h"
#include "problem.h"


void ProblemController::index()
{
    auto problemList = Problem::getAll();
    texport(problemList);
    render();
}

void ProblemController::show(const QString &problemId)
{
    auto problem = Problem::get(problemId.toInt());
    texport(problem);
    render();
}

void ProblemController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto problem = httpRequest().formItems("problem");
        auto model = Problem::create(problem);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.problemId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(problem);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ProblemController::save(const QString &problemId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Problem::get(problemId.toInt());
        if (!model.isNull()) {
            session().insert("problem_lockRevision", model.lockRevision());
            auto problem = model.toVariantMap();
            texport(problem);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("problem_lockRevision").toInt();
        auto model = Problem::get(problemId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", problemId));
            break;
        }

        auto problem = httpRequest().formItems("problem");
        model.setProperties(problem);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.problemId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(problem);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ProblemController::remove(const QString &problemId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto problem = Problem::get(problemId.toInt());
    problem.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ProblemController)
