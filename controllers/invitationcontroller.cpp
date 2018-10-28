#include "invitationcontroller.h"
#include "invitation.h"


void InvitationController::index()
{
    auto invitationList = Invitation::getAll();
    texport(invitationList);
    render();
}

void InvitationController::show(const QString &invitationId)
{
    auto invitation = Invitation::get(invitationId.toInt());
    texport(invitation);
    render();
}

void InvitationController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto invitation = httpRequest().formItems("invitation");
        auto model = Invitation::create(invitation);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.invitationId()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(invitation);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void InvitationController::save(const QString &invitationId)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Invitation::get(invitationId.toInt());
        if (!model.isNull()) {
            session().insert("invitation_lockRevision", model.lockRevision());
            auto invitation = model.toVariantMap();
            texport(invitation);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("invitation_lockRevision").toInt();
        auto model = Invitation::get(invitationId.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", invitationId));
            break;
        }

        auto invitation = httpRequest().formItems("invitation");
        model.setProperties(invitation);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.invitationId()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(invitation);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void InvitationController::remove(const QString &invitationId)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto invitation = Invitation::get(invitationId.toInt());
    invitation.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(InvitationController)
