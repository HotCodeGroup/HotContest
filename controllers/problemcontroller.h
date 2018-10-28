#ifndef PROBLEMCONTROLLER_H
#define PROBLEMCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ProblemController : public ApplicationController
{
    Q_OBJECT
public:
    ProblemController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &problemId);
    void create();
    void save(const QString &problemId);
    void remove(const QString &problemId);
};

#endif // PROBLEMCONTROLLER_H
