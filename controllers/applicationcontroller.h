#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <TActionController>
#include <boost/fiber/all.hpp>
#include <boost/array.hpp>

#include "applicationhelper.h"
#include "tester.h"

typedef boost::array<QString, 7> testInfo;

class T_CONTROLLER_EXPORT ApplicationController : public TActionController
{
    Q_OBJECT
public:
    ApplicationController();
    virtual ~ApplicationController();

    static boost::fibers::buffered_channel<testInfo> task_channel;

public slots:
    void index();
    
    void staticInitialize();
    void staticRelease();

protected:
    virtual bool preFilter();
};

#endif // APPLICATIONCONTROLLER_H
