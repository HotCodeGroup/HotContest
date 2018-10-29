#include "profilecontroller.h"
#include "profile.h"

/* Users / User / View a User Account Detail
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/user/view-a-user-account-detail
 *
 */
void ProfileController::details(const QString &userId)
{
    auto profile = Profile::get(userId.toInt());
    texport(profile);
    render();
}

/* Users / Login / Login
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/login/login
 *
 */
void ProfileController::login()
{

}

/* Users / Registration / Register
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/registration/register
 *
 */
void ProfileController::registration()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto profile = httpRequest().formItems("profile");
        auto model = Profile::create(profile);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.userId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(profile);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

/* Users / User / Edit a User Account
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/user/edit-a-user-account
 *
 */
void ProfileController::edit(const QString &userId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Profile::get(userId.toInt());
        if (!model.isNull()) {
            session().insert("profile_lockRevision", model.lockRevision());
            auto profile = model.toVariantMap();
            texport(profile);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("profile_lockRevision").toInt();
        auto model = Profile::get(userId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", userId));
            break;
        }

        auto profile = httpRequest().formItems("profile");
        model.setProperties(profile);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.userId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(profile);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

/* Users / Logout / Logout
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/user/logout
 *
 */
void ProfileController::logout(const QString &userId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto profile = Profile::get(userId.toInt());
    profile.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ProfileController)
