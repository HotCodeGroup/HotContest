#ifndef INVITATIONCONTROLLER_H
#define INVITATIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT InvitationController : public ApplicationController
{
    Q_OBJECT
public:
    InvitationController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &invitationId);
    void create();
    void save(const QString &invitationId);
    void remove(const QString &invitationId);
};

#endif // INVITATIONCONTROLLER_H
