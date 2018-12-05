#include "tester.h"

Tester::Tester(QObject *parent) : QObject(parent)
{}


void Tester::sendRequestOnList(const handleFunc &funcSuccess)
{

    QJsonObject obj;
    QJsonArray arr;
    QPair<QString, QJsonValue> p01("contestId", 1);
    QPair<QString, QJsonValue> p02("contestId", 2);
    QPair<QString, QJsonValue> p("title", "Best Contest");
    QPair<QString, QJsonValue> p1("isActive", false);
    QPair<QString, QJsonValue> p2("participantsCount", 90);
    QJsonObject ob = {p01, p, p1, p2};
    QJsonObject ob1 = {p02, p, p1, p2};
    arr.append(ob);
    arr.append(ob1);
    obj["array_data"] = arr;


    if (funcSuccess != nullptr)
        funcSuccess(obj);
}

void Tester::sendRequestOnListProblem(const handleFunc &funcSuccess)
{

    QJsonObject obj;
    QJsonArray arr;
    QPair<QString, QJsonValue> p01("problemId", 1);
    QPair<QString, QJsonValue> p02("problemId", 2);
    QPair<QString, QJsonValue> p("title", "Best Problem");
    QPair<QString, QJsonValue> p1("isDone", true);
    QPair<QString, QJsonValue> p12("isDone", false);
    QPair<QString, QJsonValue> p2("points", 45);
    QJsonObject ob = {p01, p, p1, p2};
    QJsonObject ob1 = {p02, p, p12, p2};
    arr.append(ob);
    arr.append(ob1);
    obj["array_data"] = arr;

    if (funcSuccess != nullptr)
        funcSuccess(obj);
}

void Tester::sendRequestOnContest(const handleFunc &funcSuccess)
{
    QPair<QString, QJsonValue> p0("contestId", 1);
    QPair<QString, QJsonValue> p("title", "Best Contest");
    QPair<QString, QJsonValue> p1("description", "Best Contest Contest Contest Contest Contest Contest Contest Contest Contest");
    QPair<QString, QJsonValue> p2("startTime", "2018-10-12T14:21:30");
    QPair<QString, QJsonValue> p3("finishTime", "2018-10-19T14:21:30");
    QJsonObject obj = {p0, p, p1, p2, p3};


    if (funcSuccess != nullptr)
        funcSuccess(obj);
}

void Tester::sendRequestOnProblem(const handleFunc &funcSuccess)
{
    QPair<QString, QJsonValue> p0("problemId", 1);
    QPair<QString, QJsonValue> p("title", "Best Problem");
    QPair<QString, QJsonValue> p1("description", "Best Problem Contest Problem Contest Problem Contest Problem Contest Problem");
    QPair<QString, QJsonValue> p2("timeLimit", 1000);
    QPair<QString, QJsonValue> p3("memoryLimit", 1024);
    QPair<QString, QJsonValue> p4("triesLeft", 99);
    QPair<QString, QJsonValue> p5("penaltyTry", 50);
    QPair<QString, QJsonValue> p6("penaltyTime", 2);
    QPair<QString, QJsonValue> p7("points", 55);

    QJsonObject obj = {p0, p, p1, p2, p3, p4, p5, p6, p7};


    if (funcSuccess != nullptr)
        funcSuccess(obj);
}

void Tester::sendRequestOnListSubmit(const handleFunc &funcSuccess)
{

    QJsonObject obj;
    QJsonArray arr;
    QPair<QString, QJsonValue> p01("submitId", 1);
    QPair<QString, QJsonValue> p02("submitId", 2);
    QPair<QString, QJsonValue> p("sendTime", "2019-11-12T14:21:30");
    QPair<QString, QJsonValue> p1("problemId", 5);
    QPair<QString, QJsonValue> p2("result", 0);
    QPair<QString, QJsonValue> p21("result", 1);
    QPair<QString, QJsonValue> p3("time", 440);
    QPair<QString, QJsonValue> p4("memory", 34);
    QPair<QString, QJsonValue> p51("testError", 0);
    QPair<QString, QJsonValue> p52("testError", 12);
    QPair<QString, QJsonValue> p61("points", 255);
    QPair<QString, QJsonValue> p62("points", 0);
    QJsonObject ob = {p01, p, p1, p2, p3, p4, p51, p61};
    QJsonObject ob1 = {p02, p, p1, p21, p3, p4, p52, p62};
    QJsonObject ob2 = {p02, p, p1, p21, p3, p4, p52, p62};
    arr.append(ob);
    arr.append(ob1);
    arr.append(ob2);
    obj["array_data"] = arr;

    if (funcSuccess != nullptr)
        funcSuccess(obj);
}

void Tester::sendRequestOnListSubmitShort(const handleFunc &funcSuccess)
{

    QJsonObject obj;
    QJsonArray arr;
    QPair<QString, QJsonValue> p01("submitId", 1);
    QPair<QString, QJsonValue> p02("submitId", 2);
    QPair<QString, QJsonValue> p("sendTime", "2018-11-12T14:21:30");
    QPair<QString, QJsonValue> p1("problemId", 3);
    QPair<QString, QJsonValue> p2("result", 0);
    QPair<QString, QJsonValue> p21("result", 1);
    QPair<QString, QJsonValue> p3("time", 500);
    QPair<QString, QJsonValue> p4("memory", 56);
    QPair<QString, QJsonValue> p51("testError", 0);
    QPair<QString, QJsonValue> p52("testError", 12);
    QPair<QString, QJsonValue> p61("points", 255);
    QPair<QString, QJsonValue> p62("points", 0);
    QJsonObject ob = {p01, p, p1, p2, p3, p4, p51, p61};
    QJsonObject ob1 = {p02, p, p1, p21, p3, p4, p52, p62};
    arr.append(ob);
    arr.append(ob1);
    obj["array_data"] = arr;

    if (funcSuccess != nullptr)
        funcSuccess(obj);
}


void Tester::sendRequestOnListTestSubmit(const handleFunc &funcSuccess) {
    QJsonObject obj;
    QJsonArray arr;
    QPair<QString, QJsonValue> p01("testSubmitId", 1);
    QPair<QString, QJsonValue> p02("testSubmitId", 2);
    QPair<QString, QJsonValue> p2("result", 0);
    QPair<QString, QJsonValue> p21("result", 1);
    QPair<QString, QJsonValue> p3("time", 50087676);
    QPair<QString, QJsonValue> p4("memory", 56);
    QJsonObject ob = {p01, p2, p3, p4};
    QJsonObject ob1 = {p02, p21, p3, p4};
    arr.append(ob);
    arr.append(ob1);
    obj["array_data"] = arr;

    if (funcSuccess != nullptr)
        funcSuccess(obj);
}


void Tester::sendRequestOnListParticipants(const handleFunc &funcSuccess) {
    QJsonObject obj;
    QJsonArray arr;
    arr.append("ob");
    arr.append("ob1");
    arr.append("ob2");
    obj["array_data"] = arr;

    if (funcSuccess != nullptr)
        funcSuccess(obj);
}
