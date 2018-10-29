#ifndef SUBMITCONTROLLER_H
#define SUBMITCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SubmitController : public ApplicationController
{
    Q_OBJECT
public:
    SubmitController() : ApplicationController() {}

public slots:
    void list(const QString &contestId);
    void details(const QString &contestId, const QString &submitId);
    void send_solution(const QString &contestId);
};

#endif // SUBMITCONTROLLER_H
