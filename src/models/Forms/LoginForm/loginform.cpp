#include "loginform.h"

LoginForm::LoginForm(const QString& nickname,
           const QString& password) :
nickname(nickname),
nicknameErrors(),
password(password),
passwordErrors()
{
}

LoginForm::~LoginForm() {}

const QString& LoginForm::getNickname() const {
    return nickname;
}

void LoginForm::setNickname(const QString& nickname) {
    this->nickname = nickname;
    emit nicknameChanged(this->nickname);
    validateNickname();
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
    this->password = password;
    emit passwordChanged(this->password);
    validatePassword();
}

QVector<QString>& LoginForm::getPasswordErrors() {
    return passwordErrors;
}

void LoginForm::setPasswordErrors(const QVector<QString>& passwordErrors) {
    this->passwordErrors = passwordErrors;
    emit passwordErrorsChanged(this->passwordErrors);
}

//void LoginForm::LoginController(const QJsonObject &obj) {
//    qDebug() << obj;
//    if (obj.contains("array_data") && obj["array_data"].isArray()) {
//        QJsonArray passwordErrorsArray = obj["array_data"].toArray();

//        for (int passwordErrorsIndex = 0; passwordErrorsIndex < passwordErrorsArray.size(); ++passwordErrorsIndex) {
//            LoginForm::instance()->getPasswordErrors().append(passwordErrorsArray[passwordErrorsIndex].toString());
//        }
//    }
//}

const QVariantMap LoginForm::getMap() const {
    QVariantMap resultMap({{"login", nickname},
                           {"password", password}
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
    validateNickname();
    validatePassword();
//    emit isValidChanged(isValid());
    return isValid();
}

void LoginForm::validateNickname()
{
    if (nickname.isEmpty()) {
        if (!nicknameErrors.contains("Введите никнейм")) {
            nicknameErrors.append(QString("Введите никнейм"));
            emit nicknameErrorsChanged(this->nicknameErrors);
        }
    } else {
        if (nicknameErrors.contains("Введите никнейм")) {
            nicknameErrors.removeOne("Введите никнейм");
            emit nicknameErrorsChanged(this->nicknameErrors);
        }
    }
}

void LoginForm::validatePassword()
{
    if (password.isEmpty()) {
        if (!passwordErrors.contains("Введите пароль")) {
            passwordErrors.append(QString("Введите пароль"));
            emit passwordErrorsChanged(this->passwordErrors);
        }
    } else {
        if (passwordErrors.contains("Введите пароль")) {
            passwordErrors.removeOne("Введите пароль");
            emit passwordErrorsChanged(this->passwordErrors);
        }
    }
}

void LoginForm::sendRequest() {
    if (isValid()) {
        Requester::instance()->sendRequest("users/login", nullptr, nullptr, Requester::Type::POST, getMap());
    }

//    Tester test;
//    test.sendRequestOnProblem(RegistrationController);
}
