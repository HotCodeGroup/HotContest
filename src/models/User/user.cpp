#include "user.h"

User* User::p_instance = Q_NULLPTR;

User::User(int id,
           const QString& firstName,
           const QString& lastName,
           const QString& nickname,
           const QString& email,
           const QString& password,
           bool isAuthenticated) :
id(id),
firstName(firstName),
lastName(lastName),
nickname(nickname),
email(email),
password(password),
isAuthenticated(isAuthenticated)
{}

User* User::instance() {
    if(!p_instance)
        p_instance = new User();
    return p_instance;
}

User::~User() {}

//void User::RegistrationController(const QJsonObject &obj) {

//}

//void User::LoginController(const QJsonObject &obj) {
//}

int User::getId() const {
    return id;
}

void User::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

const QString& User::getFirstName() const {
    return firstName;
}

void User::setFirstName(const QString& firstName) {
    this->firstName = firstName;
    emit firstNameChanged(this->firstName);
}

const QString& User::getLastName() const {
    return lastName;
}

void User::setLastName(const QString& lastName) {
    this->lastName = lastName;
    emit lastNameChanged(this->lastName);
}

const QString& User::getNickname() const {
    return nickname;
}

void User::setNickname(const QString& nickname) {
    this->nickname = nickname;
    emit nicknameChanged(this->nickname);
}

const QString& User::getEmail() const {
    return email;
}

void User::setEmail(const QString& email) {
    this->email = email;
    emit emailChanged(this->email);
}

const QString& User::getPassword() const {
    return password;
}

void User::setPassword(const QString& password) {
    this->password = password;
    emit passwordChanged(this->password);
}

bool User::getIsAuthenticated() const {
    return isAuthenticated;
}

void User::setIsAuthenticated(bool isAuthenticated) {
    this->isAuthenticated = isAuthenticated;
    emit isAuthenticatedChanged(this->isAuthenticated);
}

void User::auth() {
    setIsAuthenticated(true);
}

void User::logout() {
    setIsAuthenticated(false);
}

const QVariantMap User::getMap() const {
    QVariantMap resultMap({{"first_name", User::instance()->getFirstName()},
                           {"second_name", User::instance()->getLastName()},
                           {"login", User::instance()->getNickname()},
                           {"email", User::instance()->getEmail()},
                           {"password", User::instance()->getPassword()}
                          });
    return resultMap;
}

void User::sendRequest() {
//    Requester::instance()->sendRequest("registration/", RegistrationController, nullptr, Requester::Type::POST);
//    Tester test;
//    test.sendRequestOnProblem(RegistrationController);
    qDebug() << User::instance()->getMap();
}
