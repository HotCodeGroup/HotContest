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
    Q_PROPERTY(const QVector<QString>& firstNameErrors READ getFirstNameErrors WRITE setFirstNameErrors NOTIFY firstNameErrorsChanged)
    Q_PROPERTY(const QString& lastName READ getLastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY(const QVector<QString>& secondNameErrors READ getLastNameErrors WRITE setLastNameErrors NOTIFY lastNameErrorsChanged)
    Q_PROPERTY(const QString& email READ getEmail WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(const QVector<QString>& emailErrors READ getEmailErrors WRITE setEmailErrors NOTIFY emailErrorsChanged)
    Q_PROPERTY(const QString& repitPassword READ getRepitPassword WRITE setRepitPassword NOTIFY repitPasswordChanged)
    Q_PROPERTY(const QVector<QString>& repitPasswordErrors READ getRepitPasswordErrors WRITE setRepitPasswordErrors NOTIFY repitPasswordErrorsChanged)

public:
    static SignUpForm* instance();
    ~SignUpForm();

    const QString& getFirstName() const;
    void setFirstName(const QString& firstName);

    QVector<QString>& getFirstNameErrors();
    void setFirstNameErrors(const QVector<QString>& firstNameErrors);

    const QString& getLastName() const;
    void setLastName(const QString& lastName);

    QVector<QString>& getLastNameErrors();
    void setLastNameErrors(const QVector<QString>& lastNameErrors);

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
    Q_INVOKABLE static void sendRequest();

signals:
    void firstNameChanged(const QString&);
    void firstNameErrorsChanged(const QVector<QString>&);
    void lastNameChanged(const QString&);
    void lastNameErrorsChanged(const QVector<QString>&);
    void emailChanged(const QString&);
    void emailErrorsChanged(const QVector<QString>&);
    void repitPasswordChanged(const QString&);
    void repitPasswordErrorsChanged(const QVector<QString>&);

private:
    static SignUpForm* p_instance;
    SignUpForm(const QString& firstName = "",
         const QString& lastName = "", const QString& email = "",
         const QString& repitPassword = "");

    void validateFirstName();
    void validateLastName();
    void validateEmail();
    void validateRepitPassword();

    static void RegistrationController(const QJsonObject &obj);

    QString firstName;
    QVector<QString> firstNameErrors;
    QString lastName;
    QVector<QString> lastNameErrors;
    QString email;
    QVector<QString> emailErrors;
    QString repitPassword;
    QVector<QString> repitPasswordErrors;
};

#endif // SIGNUPFORM_H
