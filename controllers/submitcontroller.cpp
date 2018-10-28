#include "submitcontroller.h"
#include "submit.h"


void SubmitController::index()
{
    auto submitList = Submit::getAll();
    texport(submitList);
    render();
}

void SubmitController::show(const QString &submitId)
{
    auto submit = Submit::get(submitId.toInt());
    texport(submit);
    render();
}

void SubmitController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto submit = httpRequest().formItems("submit");
        auto model = Submit::create(submit);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.submitId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(submit);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void SubmitController::save(const QString &submitId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Submit::get(submitId.toInt());
        if (!model.isNull()) {
            session().insert("submit_lockRevision", model.lockRevision());
            auto submit = model.toVariantMap();
            texport(submit);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("submit_lockRevision").toInt();
        auto model = Submit::get(submitId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", submitId));
            break;
        }

        auto submit = httpRequest().formItems("submit");
        model.setProperties(submit);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.submitId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(submit);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void SubmitController::remove(const QString &submitId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto submit = Submit::get(submitId.toInt());
    submit.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(SubmitController)
