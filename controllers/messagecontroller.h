#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MessageController : public ApplicationController
{
    Q_OBJECT
public:
    MessageController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &messageId);
    void create();
    void save(const QString &messageId);
    void remove(const QString &messageId);
};

#endif // MESSAGECONTROLLER_H
