#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QJsonObject>
#include <QJsonArray>
#include <QQmlContext>
#include <QPair>
#include <QJsonValue>
#include <QVariant>
#include "src/models/ListContest/listofshortcontest.h"
#include "src/requester/requester.h"
#include "src/register/register.h"
#include "src/tester.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Requester::instance()->initRequester("587d7e16.ngrok.io", -1);

    QQmlApplicationEngine engine;

    Register regist(nullptr);

    engine.rootContext()->setContextProperty("regist", &regist);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
