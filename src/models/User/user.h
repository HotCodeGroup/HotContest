#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QVariantMap>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class User : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& firstName READ getFirstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(const QString& secondName READ getLastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY(const QString& nickname READ getNickname WRITE setNickname NOTIFY nicknameChanged)
    Q_PROPERTY(const QString& email READ getEmail WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(const QString& password READ getPassword WRITE setPassword NOTIFY passwordChanged)

public:
    static User* instance();
    ~User();

    int getId() const;
    void setId(int id);

    const QString& getFirstName() const;
    void setFirstName(const QString& firstName);

    const QString& getLastName() const;
    void setLastName(const QString& lastName);

    const QString& getNickname() const;
    void setNickname(const QString& nickname);

    const QString& getEmail() const;
    void setEmail(const QString& email);

    const QString& getPassword() const;
    void setPassword(const QString& password);

    const QVariantMap getMap() const;
    Q_INVOKABLE static void sendRequest();

signals:
    void idChanged(int);
    void firstNameChanged(const QString&);
    void lastNameChanged(const QString&);
    void nicknameChanged(const QString&);
    void emailChanged(const QString&);
    void passwordChanged(const QString&);

private:
    static User* p_instance;
    User(int id = 0, const QString& firstName = "",
         const QString& lastName = "", const QString& nickname = "",
         const QString& email = "", const QString& password = "");

    static void RegistrationController(const QJsonObject &obj);
    static void LoginController(const QJsonObject &obj);

    int id;
    QString firstName;
    QString lastName;
    QString nickname;
    QString email;
    QString password;
};

#endif // USER_H
