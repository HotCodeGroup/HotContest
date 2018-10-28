#ifndef CONTESTCONTROLLER_H
#define CONTESTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ContestController : public ApplicationController
{
    Q_OBJECT
public:
    ContestController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &contestId);
    void create();
    void save(const QString &contestId);
    void remove(const QString &contestId);
};

#endif // CONTESTCONTROLLER_H
