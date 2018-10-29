#include "submitcontroller.h"
#include "submit.h"

/* Contest / Submits Collection / View a submit list
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/submit/view-a-submit-details
 *
 */
void SubmitController::list(const QString &contestId)
{
    auto submitList = Submit::getAll();
    texport(submitList);
    render();
}

/* Contest / Submit / View a submit details
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/scores/view-a-scoreboard
 *
 */
void SubmitController::details(const QString &contestId, const QString &submitId)
{
    auto submit = Submit::get(submitId.toInt());
    texport(submit);
    render();
}

/* Contest / Submits Collection / Send solution
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/submits-collection/send-solution
 *
 */
void SubmitController::send_solution(const QString &contestId)
{
//    switch (httpRequest().method()) {
//    case Tf::Get: {
//        auto model = Submit::get(submitId.toInt());
//        if (!model.isNull()) {
//            session().insert("submit_lockRevision", model.lockRevision());
//            auto submit = model.toVariantMap();
//            texport(submit);
//            render();
//        }
//        break; }

//    case Tf::Post: {
//        QString error;
//        int rev = session().value("submit_lockRevision").toInt();
//        auto model = Submit::get(submitId.toInt(), rev);
        
//        if (model.isNull()) {
//            error = "Original data not found. It may have been updated/removed by another transaction.";
//            tflash(error);
//            redirect(urla("save", submitId));
//            break;
//        }

//        auto submit = httpRequest().formItems("submit");
//        model.setProperties(submit);
//        if (model.save()) {
//            QString notice = "Updated successfully.";
//            tflash(notice);
//            redirect(urla("show", model.submitId()));
//        } else {
//            error = "Failed to update.";
//            texport(error);
//            texport(submit);
//            render();
//        }
//        break; }

//    default:
//        renderErrorResponse(Tf::NotFound);
//        break;
//    }
}


// Don't remove below this line
T_DEFINE_CONTROLLER(SubmitController)
