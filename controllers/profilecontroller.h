#ifndef PROFILECONTROLLER_H
#define PROFILECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ProfileController : public ApplicationController
{
    Q_OBJECT
public:
    ProfileController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &userId);
    void create();
    void save(const QString &userId);
    void remove(const QString &userId);
};

#endif // PROFILECONTROLLER_H
