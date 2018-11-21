#ifndef PROBLEMCONTROLLER_H
#define PROBLEMCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ProblemController : public ApplicationController
{
Q_OBJECT
public:
    ProblemController() : ApplicationController() {}

public slots:
    void list(const QString &contestId);
    void create(const QString &contestId);

    void details(const QString &contestId, const QString &problemId);
    void edit(const QString &contestId, const QString &problemId);
    void remove(const QString &contestId, const QString &problemId);
};

#endif // PROBLEMCONTROLLER_H
