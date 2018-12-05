#ifndef TESTER_H
#define TESTER_H

#include <QObject>
#include <QBuffer>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <functional>

class Tester : public QObject
{
    Q_OBJECT
public:
    typedef std::function<void(const QJsonObject &)> handleFunc;


    explicit Tester(QObject *parent = Q_NULLPTR);

    void sendRequestOnList(const handleFunc &funcSuccess);
    void sendRequestOnContest(const handleFunc &funcSuccess);
    void sendRequestOnListProblem(const handleFunc &funcSuccess);
    void sendRequestOnProblem(const handleFunc &funcSuccess);
    void sendRequestOnListSubmitShort(const handleFunc &funcSuccess);
    void sendRequestOnListSubmit(const handleFunc &funcSuccess);
    void sendRequestOnListTestSubmit(const handleFunc &funcSuccess);
    void sendRequestOnListParticipants(const handleFunc &funcSuccess);

private:


public slots:
};

#endif // TESTER_H
