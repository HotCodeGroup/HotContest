#include "loginform.h"

LoginForm* LoginForm::p_instance = Q_NULLPTR;

LoginForm::LoginForm(const QString& nickname,
           const QString& password) :
nickname(nickname),
nicknameErrors(),
password(password),
passwordErrors()
{}

LoginForm* LoginForm::instance() {
    if(!p_instance)
        p_instance = new LoginForm();
    return p_instance;
}

LoginForm::~LoginForm() {}

const QString& LoginForm::getNickname() const {
    return nickname;
}

void LoginForm::setNickname(const QString& nickname) {
    this->nickname = nickname.simplified();
    emit nicknameChanged(this->nickname);
}

QVector<QString>& LoginForm::getNicknameErrors() {
    return nicknameErrors;
}

void LoginForm::setNicknameErrors(const QVector<QString>& nicknameErrors) {
    this->nicknameErrors = nicknameErrors;
    emit nicknameErrorsChanged(this->nicknameErrors);
}

const QString& LoginForm::getPassword() const {
    return password;
}

void LoginForm::setPassword(const QString& password) {
    this->password = password.simplified();
    emit passwordChanged(this->password);
}

QVector<QString>& LoginForm::getPasswordErrors() {
    return passwordErrors;
}

void LoginForm::setPasswordErrors(const QVector<QString>& passwordErrors) {
    this->passwordErrors = passwordErrors;
    emit passwordErrorsChanged(this->passwordErrors);
}

void LoginForm::LoginController(const QJsonObject &obj) {
    qDebug() << obj;
    if (obj.contains("array_data") && obj["array_data"].isArray()) {
        QJsonArray passwordErrorsArray = obj["array_data"].toArray();

        for (int passwordErrorsIndex = 0; passwordErrorsIndex < passwordErrorsArray.size(); ++passwordErrorsIndex) {
            LoginForm::instance()->getPasswordErrors().append(passwordErrorsArray[passwordErrorsIndex].toString());
        }
    }
}

const QVariantMap LoginForm::getMap() const {
    QVariantMap resultMap({{"login", LoginForm::instance()->getNickname()},
                           {"password", LoginForm::instance()->getPassword()}
                          });
    return resultMap;
}

bool LoginForm::isValid() const
{
    return nicknameErrors.isEmpty()
            && passwordErrors.isEmpty()
            && !nickname.isEmpty()
            && !password.isEmpty();
}

bool LoginForm::validate()
{
    nicknameErrors.clear();
    passwordErrors.clear();
    validatePassword();
//    emit isValidChanged(isValid());
    return isValid();
}

void LoginForm::validatePassword()
{
    if (password.isEmpty()) {
        passwordErrors.append(QString("Введите пароль"));
    }
}

void LoginForm::sendRequest() {
    if (LoginForm::instance()->isValid()) {
        Requester::instance()->sendRequest("users/login", LoginController, nullptr, Requester::Type::POST, LoginForm::instance()->getMap());
    }

//    Tester test;
//    test.sendRequestOnProblem(RegistrationController);
}
