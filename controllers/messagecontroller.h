#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MessageController : public ApplicationController
{
    Q_OBJECT
public:
    MessageController() : ApplicationController() {}

public slots:
    void list(const QString &contestId);
    void create(const QString &contestId);
    
    void details(const QString &contestId, const QString &messageId);
};

#endif // MESSAGECONTROLLER_H
