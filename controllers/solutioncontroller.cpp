#include "solutioncontroller.h"
#include "solution.h"

/* Contest / Solution / Send solution
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/contest/solution/send-solution
 *
 */
void SolutionController::create(const QString &contestId, const QString &problemPos)
{
//    switch (httpRequest().method()) {
//    case Tf::Get:
//        render();
//        break;
//
//    case Tf::Post: {
//        auto solution = httpRequest().formItems("solution");
//        auto model = Solution::create(solution);
//
//        if (!model.isNull()) {
//            QString notice = "Created successfully.";
//            tflash(notice);
//            redirect(urla("show", model.solutionId()));
//        } else {
//            QString error = "Failed to create.";
//            texport(error);
//            texport(solution);
//            render();
//        }
//        break; }
//
//    default:
//        renderErrorResponse(Tf::NotFound);
//        break;
//    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(SolutionController)
