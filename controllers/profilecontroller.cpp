#include "profilecontroller.h"
#include "profile.h"


void ProfileController::index()
{
    auto profileList = Profile::getAll();
    texport(profileList);
    render();
}

void ProfileController::show(const QString &userId)
{
    auto profile = Profile::get(userId.toInt());
    texport(profile);
    render();
}

void ProfileController::create()
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

void ProfileController::save(const QString &userId)
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

void ProfileController::remove(const QString &userId)
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
