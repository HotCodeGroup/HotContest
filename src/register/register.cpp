#include "register.h"
#include <QtQml>

#include "src/models/ShortContest/shortcontest.h"
#include "src/models/ListContest/listofshortcontest.h"
#include "src/models/Contest/contest.h"
#include "src/models/ListProblem/listofshortproblem.h"
#include "src/models/ShortProblem/shortproblem.h"
#include "src/models/Problem/problem.h"
#include "src/models/Submit/submit.h"
#include "src/models/ListSubmits/listofsubmit.h"
#include "src/models/TestSubmit/testsubmit.h"
#include "src/models/ListTestSubmit/listoftestsubmit.h"
#include "src/models/Participant/participant.h"
#include "src/models/ListParticipants/listofparticipants.h"
#include "src/models/User/user.h"
#include "src/models/Forms/SignUpForm/signupform.h"
#include "src/models/Forms/LoginForm/loginform.h"
#include "src/utils/stateinfo.h"

Register::Register(QObject *parent) :
    QObject(parent)
{
    registerTypes();
}

void Register::registerTypes() const {
    qmlRegisterType<ShortContest>("models", 1, 0, "ShortContest");
    qmlRegisterType<ShortProblem>("models", 1, 0, "ShortProblem");
    qmlRegisterType<TestSubmit>("models", 1, 0, "TestSubmit");
    qmlRegisterType<Participant>("models", 1, 0, "Participant");
    qmlRegisterType<Submit>("models", 1, 0, "M_Submit");
    qmlRegisterType<StateInfo>("models", 1, 0, "StateInfo");
    qmlRegisterSingletonType<ListOfShortContest>("models", 1, 0, "ListOfShortContest",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(ListOfShortContest::instance));
    qmlRegisterSingletonType<Contest>("models", 1, 0, "M_Contest",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(Contest::instance));
    qmlRegisterSingletonType<Problem>("models", 1, 0, "M_Problem",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(Problem::instance));
    qmlRegisterSingletonType<ListOfShortProblem>("models", 1, 0, "ListOfShortProblem",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(ListOfShortProblem::instance));
    qmlRegisterSingletonType<ListOfSubmit>("models", 1, 0, "ListOfSubmit",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(ListOfSubmit::instance));
    qmlRegisterSingletonType<ListOfTestSubmit>("models", 1, 0, "ListOfTestSubmit",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(ListOfTestSubmit::instance));
    qmlRegisterSingletonType<ListOfParticipants>("models", 1, 0, "ListOfParticipants",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(ListOfParticipants::instance));
    qmlRegisterSingletonType<User>("models", 1, 0, "User",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(User::instance));
    qmlRegisterSingletonType<SignUpForm>("models", 1, 0, "SignUpForm",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(SignUpForm::instance));
    qmlRegisterSingletonType<LoginForm>("models", 1, 0, "LoginForm",
                                                 reinterpret_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(LoginForm::instance));
}
