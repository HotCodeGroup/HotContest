#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TestController : public ApplicationController
{
    Q_OBJECT
public:
    TestController() : ApplicationController() {}

public slots:
    void list(const QString &contestId, const QString &problemId);
    void create(const QString &contestId, const QString &problemId);

    void details(const QString &contestId, const QString &problemId, const QString &testId);
    void edit(const QString &contestId, const QString &problemId, const QString &testId);
    void remove(const QString &contestId, const QString &problemId, const QString &testId);
};

#endif // TESTCONTROLLER_H
