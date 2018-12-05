#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QVariantMap>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class LoginForm : public QObject {

    Q_OBJECT
    Q_PROPERTY(const QString& nickname READ getNickname WRITE setNickname NOTIFY nicknameChanged)
    Q_PROPERTY(const QVector<QString>& nicknameErrors READ getNicknameErrors WRITE setNicknameErrors NOTIFY nicknameErrorsChanged)
    Q_PROPERTY(const QString& password READ getPassword WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(const QVector<QString>& passwordErrors READ getPasswordErrors WRITE setPasswordErrors NOTIFY passwordErrorsChanged)
    Q_PROPERTY(bool isValid READ isValid NOTIFY isValidChanged)

public:
    static LoginForm* instance();
    ~LoginForm();

    const QString& getNickname() const;
    void setNickname(const QString& nickname);

    QVector<QString>& getNicknameErrors();
    void setNicknameErrors(const QVector<QString>& nicknameErrors);

    const QString& getPassword() const;
    void setPassword(const QString& password);

    QVector<QString>& getPasswordErrors();
    void setPasswordErrors(const QVector<QString>& passwordErrors);

    const QVariantMap getMap() const;
    bool isValid() const;

    Q_INVOKABLE bool validate();
    Q_INVOKABLE static void sendRequest();

signals:
    void nicknameChanged(const QString&);
    void nicknameErrorsChanged(const QVector<QString>&);
    void passwordChanged(const QString&);
    void passwordErrorsChanged(const QVector<QString>&);
    void isValidChanged(bool);

protected:
    static LoginForm* p_instance;
    LoginForm(const QString& nickname = "",
              const QString& password = "");

    void validatePassword();

    static void LoginController(const QJsonObject &obj);

    QString nickname;
    QVector<QString> nicknameErrors;
    QString password;
    QVector<QString> passwordErrors;
};

#endif // SIGNUPFORM_H
