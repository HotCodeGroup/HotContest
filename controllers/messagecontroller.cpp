#include "messagecontroller.h"
#include "message.h"


void MessageController::index()
{
    auto messageList = Message::getAll();
    texport(messageList);
    render();
}

void MessageController::show(const QString &messageId)
{
    auto message = Message::get(messageId.toInt());
    texport(message);
    render();
}

void MessageController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto message = httpRequest().formItems("message");
        auto model = Message::create(message);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.messageId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(message);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void MessageController::save(const QString &messageId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Message::get(messageId.toInt());
        if (!model.isNull()) {
            session().insert("message_lockRevision", model.lockRevision());
            auto message = model.toVariantMap();
            texport(message);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("message_lockRevision").toInt();
        auto model = Message::get(messageId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", messageId));
            break;
        }

        auto message = httpRequest().formItems("message");
        model.setProperties(message);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.messageId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(message);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void MessageController::remove(const QString &messageId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto message = Message::get(messageId.toInt());
    message.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(MessageController)
