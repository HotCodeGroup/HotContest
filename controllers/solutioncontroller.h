#ifndef SOLUTIONCONTROLLER_H
#define SOLUTIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SolutionController : public ApplicationController
{
    Q_OBJECT
public:
    SolutionController() : ApplicationController() {}

public slots:
    void create(const QString &contestId, const QString &problemPos);
};

#endif // SOLUTIONCONTROLLER_H
