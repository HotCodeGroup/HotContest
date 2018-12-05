#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UserController : public ApplicationController
{
    Q_OBJECT
public:
    UserController() : ApplicationController() { }

public slots:
    void login();
    void logout();
};

#endif // USERCONTROLLER_H
