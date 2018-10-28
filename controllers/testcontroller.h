#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TestController : public ApplicationController
{
    Q_OBJECT
public:
    TestController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &testId);
    void create();
    void save(const QString &testId);
    void remove(const QString &testId);
};

#endif // TESTCONTROLLER_H
