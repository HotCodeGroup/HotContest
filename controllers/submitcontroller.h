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

private:
    static int testsLimit;
    static int items_per_page;
    static int show_around;
};

#endif // SUBMITCONTROLLER_H
