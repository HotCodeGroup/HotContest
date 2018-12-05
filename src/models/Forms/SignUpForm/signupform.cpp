#include "signupform.h"

SignUpForm* SignUpForm::p_instance = Q_NULLPTR;

SignUpForm::SignUpForm(const QString& firstName,
           const QString& lastName,
           const QString& email,
           const QString& repitPassword) :
firstName(firstName),
firstNameErrors(),
lastName(lastName),
lastNameErrors(),
email(email),
emailErrors(),
repitPassword(repitPassword),
repitPasswordErrors()
{}

SignUpForm* SignUpForm::instance() {
    if(!p_instance)
        p_instance = new SignUpForm();
    return p_instance;
}

SignUpForm::~SignUpForm() {}

void SignUpForm::RegistrationController(const QJsonObject &obj) {
    qDebug() << obj;

}

const QString& SignUpForm::getFirstName() const {
    return firstName;
}

void SignUpForm::setFirstName(const QString& firstName) {
    this->firstName = firstName.simplified();
    emit firstNameChanged(this->firstName);
}

QVector<QString>& SignUpForm::getFirstNameErrors() {
    return firstNameErrors;
}

void SignUpForm::setFirstNameErrors(const QVector<QString>& firstNameErrors) {
    this->firstNameErrors = firstNameErrors;
    emit firstNameErrorsChanged(this->firstNameErrors);
}

const QString& SignUpForm::getLastName() const {
    return lastName;
}

void SignUpForm::setLastName(const QString& lastName) {
    this->lastName = lastName.simplified();
    emit lastNameChanged(this->lastName);
}

QVector<QString>& SignUpForm::getLastNameErrors() {
    return nicknameErrors;
}

void SignUpForm::setLastNameErrors(const QVector<QString>& lastNameErrors) {
    this->lastNameErrors = lastNameErrors;
    emit lastNameErrorsChanged(this->lastNameErrors);
}

const QString& SignUpForm::getEmail() const {
    return email;
}

void SignUpForm::setEmail(const QString& email) {
    this->email = email.simplified();
    emit emailChanged(this->email);
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
    this->repitPassword = repitPassword.simplified();
    emit repitPasswordChanged(this->repitPassword);
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
    return /*LoginForm::isValid() &&*/
            firstNameErrors.isEmpty()
            && lastNameErrors.isEmpty()
            && emailErrors.isEmpty()
            && repitPasswordErrors.isEmpty()
            && !firstName.isEmpty()
            && !lastName.isEmpty()
            && !email.isEmpty()
            && !repitPassword.isEmpty();
}

bool SignUpForm::validate()
{
    LoginForm::validate();
    firstNameErrors.clear();
    lastNameErrors.clear();
    emailErrors.clear();
    repitPasswordErrors.clear();
    validateFirstName();
    validateLastName();
    validateEmail();
    validateRepitPassword();
//    emit isValidChanged(isValid());
    return isValid();
}

const QVariantMap SignUpForm::getMap() const {
    QVariantMap resultMap({{"first_name", SignUpForm::instance()->getFirstName()},
                           {"last_name", SignUpForm::instance()->getLastName()},
                           {"username", LoginForm::instance()->getNickname()},
                           {"email", SignUpForm::instance()->getEmail()},
                           {"password", LoginForm::instance()->getPassword()}
                          });
    return resultMap;
}

void SignUpForm::sendRequest() {
    if (SignUpForm::instance()->isValid()) {
        Requester::instance()->sendRequest("users/signup", RegistrationController, nullptr, Requester::Type::POST, SignUpForm::instance()->getMap());
    }
}

void SignUpForm::validateFirstName()
{
    if (firstName.isEmpty()) {
        firstNameErrors.append(QString("Введите ваше имя"));
    }
}

void SignUpForm::validateLastName()
{
    if (lastName.isEmpty()) {
        lastNameErrors.append(QString("Введите вашу фамилию"));
    }
}

void SignUpForm::validateEmail()
{
    if (email.isEmpty()) {
        emailErrors.append(QString("Введите адрес электронной почты"));
    }
}

void SignUpForm::validateRepitPassword()
{
    if (repitPassword.isEmpty()) {
        repitPasswordErrors.append(QString("Повторите ваш пароль"));
    }
}
