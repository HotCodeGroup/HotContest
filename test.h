#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QBuffer>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <functional>

class Test : public QObject
{
    Q_OBJECT
public:
    typedef std::function<void(const QJsonObject &)> handleFunc;


    explicit Test(QObject *parent = Q_NULLPTR);

    void sendRequest(const handleFunc &funcSuccess);

private:


public slots:
};

#endif // TEST_H
