#ifndef TESTSUBMITCONTROLLER_H
#define TESTSUBMITCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TestSubmitController : public ApplicationController
{
    Q_OBJECT
public:
    TestSubmitController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &testSubmitId);
    void create();
    void save(const QString &testSubmitId);
    void remove(const QString &testSubmitId);
};

#endif // TESTSUBMITCONTROLLER_H
