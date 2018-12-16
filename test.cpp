#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{}


void Test::sendRequest(const handleFunc &funcSuccess)
{

    QJsonObject obj;
    QJsonArray arr;
    QPair<QString, QJsonValue> p0("contestId", 1);
    QPair<QString, QJsonValue> p("title", "Best Contest");
    QPair<QString, QJsonValue> p1("isActive", true);
    QPair<QString, QJsonValue> p2("participantsCount", 89);
    QJsonObject ob = {p0, p, p1, p2};
    QJsonObject ob1 = {p0, p, p1, p2};
    arr.append(ob);
    arr.append(ob1);
    obj["array_data"] = arr;


    qDebug() << obj;
    if (funcSuccess != nullptr)
        funcSuccess(obj);
}
