#ifndef SCORESCONTROLLER_H
#define SCORESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ScoresController : public ApplicationController
{
    Q_OBJECT
public:
    ScoresController() : ApplicationController() {}

public slots:
    void list(const QString &contestId);
};

#endif // SCORESCONTROLLER_H
