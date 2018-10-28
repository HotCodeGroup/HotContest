#ifndef SUBMITCONTROLLER_H
#define SUBMITCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SubmitController : public ApplicationController
{
    Q_OBJECT
public:
    SubmitController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &submitId);
    void create();
    void save(const QString &submitId);
    void remove(const QString &submitId);
};

#endif // SUBMITCONTROLLER_H
