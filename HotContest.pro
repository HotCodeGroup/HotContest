QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/models/Contest/contest.cpp \
    src/models/Problem/problem.cpp \
    src/models/ShortContest/shortcontest.cpp \
    src/models/ShortProblem/shortproblem.cpp \
    src/models/ListContest/listofshortcontest.cpp \
    src/models/ListProblem/listofshortproblem.cpp \
    src/models/Submit/submit.cpp \
    src/models/ListSubmits/listofsubmit.cpp \
    src/models/TestSubmit/testsubmit.cpp \
    src/models/ListTestSubmit/listoftestsubmit.cpp \
    src/models/Participant/participant.cpp \
    src/models/ListParticipants/listofparticipants.cpp \
    src/models/User/user.cpp \
    src/models/Forms/CreateContestForm/createcontestform.cpp \
    src/models/Forms/SignUpForm/signupform.cpp \
    src/models/Forms/LoginForm/loginform.cpp \
    src/utils/stateinfo.cpp \
    src/register/register.cpp \
    src/requester/requester.cpp \
    src/tester.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    models.pri

HEADERS += \
    src/models/Contest/contest.h \
    src/models/Problem/problem.h \
    src/models/ShortContest/shortcontest.h \
    src/models/ShortProblem/shortproblem.h \
    src/models/Submit/submit.h \
#    src/models/Test/test.h \
    src/models/TestSubmit/testsubmit.h \
    src/models/User/user.h \
    src/models/Forms/CreateContestForm/createcontestform.h \
    src/models/Forms/SignUpForm/signupform.h \
    src/models/Forms/LoginForm/loginform.h \
    src/models/ListContest/listofshortcontest.h \
    src/models/ListProblem/listofshortproblem.h \
    src/models/Participant/participant.h \
    src/models/ListParticipants/listofparticipants.h \
    src/models/ListSubmits/listofsubmit.h \
    src/models/ListTestSubmit/listoftestsubmit.h \
#    models/tableofresult.h \
#    models/shorttableofresult.h \
    src/utils/stateinfo.h \
    src/requester/requester.h \
    src/register/register.h \
    src/tester.h \
