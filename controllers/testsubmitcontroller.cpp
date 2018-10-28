#include "testsubmitcontroller.h"
#include "testsubmit.h"


void TestSubmitController::index()
{
    auto testSubmitList = TestSubmit::getAll();
    texport(testSubmitList);
    render();
}

void TestSubmitController::show(const QString &testSubmitId)
{
    auto testSubmit = TestSubmit::get(testSubmitId.toInt());
    texport(testSubmit);
    render();
}

void TestSubmitController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto testSubmit = httpRequest().formItems("testSubmit");
        auto model = TestSubmit::create(testSubmit);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.testSubmitId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(testSubmit);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TestSubmitController::save(const QString &testSubmitId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = TestSubmit::get(testSubmitId.toInt());
        if (!model.isNull()) {
            session().insert("testSubmit_lockRevision", model.lockRevision());
            auto testSubmit = model.toVariantMap();
            texport(testSubmit);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("testSubmit_lockRevision").toInt();
        auto model = TestSubmit::get(testSubmitId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", testSubmitId));
            break;
        }

        auto testSubmit = httpRequest().formItems("testSubmit");
        model.setProperties(testSubmit);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.testSubmitId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(testSubmit);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TestSubmitController::remove(const QString &testSubmitId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto testSubmit = TestSubmit::get(testSubmitId.toInt());
    testSubmit.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(TestSubmitController)
