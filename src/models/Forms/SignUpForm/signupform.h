#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QVariantMap>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"
#include "src/models/Forms/LoginForm/loginform.h"

class SignUpForm : public LoginForm {

    Q_OBJECT
    Q_PROPERTY(const QString& firstName READ getFirstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(const QString& lastName READ getLastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY(const QString& email READ getEmail WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(const QVector<QString>& emailErrors READ getEmailErrors WRITE setEmailErrors NOTIFY emailErrorsChanged)
    Q_PROPERTY(const QString& repitPassword READ getRepitPassword WRITE setRepitPassword NOTIFY repitPasswordChanged)
    Q_PROPERTY(const QVector<QString>& repitPasswordErrors READ getRepitPasswordErrors WRITE setRepitPasswordErrors NOTIFY repitPasswordErrorsChanged)

public:
    SignUpForm(const QString& firstName = "",
         const QString& lastName = "", const QString& email = "",
         const QString& repitPassword = "");
    ~SignUpForm();

    const QString& getFirstName() const;
    void setFirstName(const QString& firstName);

    const QString& getLastName() const;
    void setLastName(const QString& lastName);

    const QString& getEmail() const;
    void setEmail(const QString& email);

    QVector<QString>& getEmailErrors();
    void setEmailErrors(const QVector<QString>& emailErrors);

    const QString& getRepitPassword() const;
    void setRepitPassword(const QString& repitPassword);

    QVector<QString>& getRepitPasswordErrors();
    void setRepitPasswordErrors(const QVector<QString>& repitPasswordErrors);

    const QVariantMap getMap() const;
    bool isValid() const;

    Q_INVOKABLE bool validate();
    Q_INVOKABLE void sendRequest();

signals:
    void firstNameChanged(const QString&);
    void lastNameChanged(const QString&);
    void emailChanged(const QString&);
    void emailErrorsChanged(const QVector<QString>&);
    void repitPasswordChanged(const QString&);
    void repitPasswordErrorsChanged(const QVector<QString>&);

private:
    void validateEmail();
    void validateRepitPassword();

    static void RegistrationController(const QJsonObject &obj);

    QString firstName;
    QString lastName;
    QString email;
    QVector<QString> emailErrors;
    QString repitPassword;
    QVector<QString> repitPasswordErrors;
};

#endif // SIGNUPFORM_H
