#ifndef REQUESTER_H
#define REQUESTER_H

#include <QObject>
#include <QBuffer>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <functional>

class Requester : public QObject
{
    Q_OBJECT
public:
    static Requester* instance();
    typedef std::function<void(const QJsonObject &)> handleFunc;
    typedef std::function<void()> finishFunc;

    static const QString KEY_QNETWORK_REPLY_ERROR;
    static const QString KEY_CONTENT_NOT_FOUND;

    enum class Type {
        POST,
        GET,
        PATCH,
        DELET
    };

    void initRequester(const QString& host, int port);

    void sendRequest(const QString &apiStr,
                     const handleFunc &funcSuccess,
                     const handleFunc &funcError,
                     Type type = Type::GET,
                     const QVariantMap &data = QVariantMap());

    QString getToken() const;
    void setToken(const QString &value);

private:
    static Requester* p_instance;
    static const QString httpTemplate;
    static const QString httpPortTemplate;

    explicit Requester(QObject *parent = Q_NULLPTR);

    QString host;
    int port;
    QString token;

    QString pathTemplate;

    QByteArray variantMapToJson(QVariantMap data);

    QNetworkRequest createRequest(const QString &apiStr);

    QNetworkReply *sendCustomRequest(QNetworkAccessManager *manager,
                                     QNetworkRequest &request,
                                     const QString &type,
                                     const QVariantMap &data);

    QJsonObject parseReply(QNetworkReply *reply);

    bool onFinishRequest(QNetworkReply *reply);

    void handleQtNetworkErrors(QNetworkReply *reply, QJsonObject &obj);
    QNetworkAccessManager *manager;

signals:
    void networkError();


public slots:
};

#endif // REQUESTER_H
