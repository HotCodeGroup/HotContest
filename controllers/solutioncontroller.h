#ifndef SOLUTIONCONTROLLER_H
#define SOLUTIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SolutionController : public ApplicationController
{
    Q_OBJECT
public:
    SolutionController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &solutionId);
    void create();
    void save(const QString &solutionId);
    void remove(const QString &solutionId);
};

#endif // SOLUTIONCONTROLLER_H
