#ifndef PROFILECONTROLLER_H
#define PROFILECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ProfileController : public ApplicationController
{
    Q_OBJECT
public:
    ProfileController() : ApplicationController() {}

public slots:
    void signup();

    void details(const QString &userId);
    void edit(const QString &userId);
};

#endif // PROFILECONTROLLER_H
