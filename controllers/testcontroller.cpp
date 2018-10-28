#include "testcontroller.h"
#include "test.h"


void TestController::index()
{
    auto testList = Test::getAll();
    texport(testList);
    render();
}

void TestController::show(const QString &testId)
{
    auto test = Test::get(testId.toInt());
    texport(test);
    render();
}

void TestController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto test = httpRequest().formItems("test");
        auto model = Test::create(test);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.testId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(test);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TestController::save(const QString &testId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Test::get(testId.toInt());
        if (!model.isNull()) {
            session().insert("test_lockRevision", model.lockRevision());
            auto test = model.toVariantMap();
            texport(test);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("test_lockRevision").toInt();
        auto model = Test::get(testId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", testId));
            break;
        }

        auto test = httpRequest().formItems("test");
        model.setProperties(test);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.testId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(test);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TestController::remove(const QString &testId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto test = Test::get(testId.toInt());
    test.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(TestController)
