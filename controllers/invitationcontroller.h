#ifndef INVITATIONCONTROLLER_H
#define INVITATIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT InvitationController : public ApplicationController
{
    Q_OBJECT
public:
    InvitationController() : ApplicationController() {}

public slots:
    void list(const QString &contestId);
    void create(const QString &contestId);

    void answer(const QString &contestId, const QString &invitationId);
    void remove(const QString &contestId, const QString &invitationId);
};

#endif // INVITATIONCONTROLLER_H
