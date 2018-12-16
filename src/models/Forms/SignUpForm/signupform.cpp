#include "signupform.h"

SignUpForm::SignUpForm(const QString& firstName,
           const QString& lastName,
           const QString& email,
           const QString& repitPassword) :
firstName(firstName),
lastName(lastName),
email(email),
emailErrors(),
repitPassword(repitPassword),
repitPasswordErrors()
{
}

SignUpForm::~SignUpForm() {}

void SignUpForm::RegistrationController(const QJsonObject &obj) {
    qDebug() << obj;

}

const QString& SignUpForm::getFirstName() const {
    return firstName;
}

void SignUpForm::setFirstName(const QString& firstName) {
    this->firstName = firstName;
    emit firstNameChanged(this->firstName);
}

const QString& SignUpForm::getLastName() const {
    return lastName;
}

void SignUpForm::setLastName(const QString& lastName) {
    this->lastName = lastName;
    emit lastNameChanged(this->lastName);
}

const QString& SignUpForm::getEmail() const {
    return email;
}

void SignUpForm::setEmail(const QString& email) {
    this->email = email;
    emit emailChanged(this->email);
    validateEmail();
}

QVector<QString>& SignUpForm::getEmailErrors() {
    return emailErrors;
}

void SignUpForm::setEmailErrors(const QVector<QString>& emailErrors) {
    this->emailErrors = emailErrors;
    emit emailErrorsChanged(this->emailErrors);
}

const QString& SignUpForm::getRepitPassword() const {
    return repitPassword;
}

void SignUpForm::setRepitPassword(const QString& repitPassword) {
    this->repitPassword = repitPassword;
    emit repitPasswordChanged(this->repitPassword);
    validateRepitPassword();
}

QVector<QString>& SignUpForm::getRepitPasswordErrors() {
    return repitPasswordErrors;
}

void SignUpForm::setRepitPasswordErrors(const QVector<QString>& repitPasswordErrors) {
    this->repitPasswordErrors = repitPasswordErrors;
    emit repitPasswordErrorsChanged(this->repitPasswordErrors);
}

bool SignUpForm::isValid() const
{
    return LoginForm::isValid()
            && emailErrors.isEmpty()
            && repitPasswordErrors.isEmpty()
            && !email.isEmpty()
            && !repitPassword.isEmpty();
}

bool SignUpForm::validate()
{
    LoginForm::validate();
    validateEmail();
    validateRepitPassword();
//    emit isValidChanged(isValid());
    return isValid();
}

const QVariantMap SignUpForm::getMap() const {
    QVariantMap resultMap({{"first_name", firstName},
                           {"last_name",lastName},
                           {"username", nickname},
                           {"email", email},
                           {"password", password}
                          });
    return resultMap;
}

void SignUpForm::sendRequest() {
    if (isValid()) {
        Requester::instance()->sendRequest("users/signup", RegistrationController, nullptr, Requester::Type::POST, getMap());
    }
}

void SignUpForm::validateEmail()
{
    if (email.isEmpty()) {
        if (!emailErrors.contains("Введите адрес электронной почты")) {
            emailErrors.append(QString("Введите адрес электронной почты"));
            emit emailErrorsChanged(this->emailErrors);
        }
    } else {
        if (emailErrors.contains("Введите адрес электронной почты")) {
            emailErrors.removeOne("Введите адрес электронной почты");
            emit emailErrorsChanged(this->emailErrors);
        }
    }
}

void SignUpForm::validateRepitPassword()
{
    if (repitPassword.isEmpty()) {
        if (!repitPasswordErrors.contains("Повторите ваш пароль")) {
            repitPasswordErrors.append(QString("Повторите ваш пароль"));
            emit repitPasswordErrorsChanged(this->repitPasswordErrors);
        }
    } else {
        if (repitPasswordErrors.contains("Повторите ваш пароль")) {
            repitPasswordErrors.removeOne("Повторите ваш пароль");
            emit repitPasswordErrorsChanged(this->repitPasswordErrors);
        }
    }
}
