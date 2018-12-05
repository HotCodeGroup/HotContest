#ifndef PARTICIPANTSCONTROLLER_H
#define PARTICIPANTSCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT ParticipantsController : public ApplicationController
{
    Q_OBJECT
public:
    ParticipantsController() : ApplicationController() {}

public slots:
    void list(const QString &contestId);

private:
    static int items_per_page;
    static int show_around;
};

#endif // PARTICIPANTSCONTROLLER_H
