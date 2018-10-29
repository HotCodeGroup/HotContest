#ifndef CONTESTCONTROLLER_H
#define CONTESTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ContestController : public ApplicationController
{
    Q_OBJECT
public:
    ContestController() : ApplicationController() {}

public slots:
    void details(const QString &contestId);
    void create();
    void edit(const QString &contestId);
    void leave(const QString &contestId);

    void list();
};

#endif // CONTESTCONTROLLER_H
