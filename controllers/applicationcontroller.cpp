#include "applicationcontroller.h"


ApplicationController::ApplicationController()
    : TActionController()
{ }

ApplicationController::~ApplicationController()
{ }

/* HotContest API Root / Retrieve the Entry Point
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#introduction/description-of-usual-server-responses:
 * 
 */ 
void ApplicationController::index()
{
    QVariantMap commands;
    commands["contestsURL"] = "/contests";
    commands["usersURL"] = "/users";

    renderJson(commands);
}

void ApplicationController::staticInitialize()
{ }

void ApplicationController::staticRelease()
{ }

bool ApplicationController::preFilter()
{
    return true;
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApplicationController)
