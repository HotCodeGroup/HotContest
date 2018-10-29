#include "messagecontroller.h"
#include "message.h"

/* Contest / Messages Collection / View a Messages list
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/message/view-a-messages-list
 *
 */
void MessageController::list(const QString &contestId)
{
    auto messageList = Message::getAll();
    texport(messageList);
    render();
}

/* Contest / Message / View a Message Detail
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/message/view-a-message-detail
 *
 */
void MessageController::details(const QString &contestId, const QString &messageId)
{
    auto message = Message::get(messageId.toInt());
    texport(message);
    render();
}

/* Contest / Messages Collection / Send Message
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/messages-collection/send-message
 *
 */
void MessageController::create(const QString &contestId)
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

// Don't remove below this line
T_DEFINE_CONTROLLER(MessageController)
