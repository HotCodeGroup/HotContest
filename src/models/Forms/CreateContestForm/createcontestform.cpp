#include "createcontestform.h"

CreateContestForm::CreateContestForm(const QString& title) :
title(title)
{
}

CreateContestForm::~CreateContestForm() {}

const QString& CreateContestForm::getTitle() const {
    return title;
}

void CreateContestForm::setTitle(const QString& title) {
    this->title = title;
    emit titleChanged(this->title);
    validateTitle();
}

QVector<QString>& CreateContestForm::getTitleErrors() {
    return titleErrors;
}

void CreateContestForm::setTitleErrors(const QVector<QString>& titleErrors) {
    this->titleErrors = titleErrors;
    emit titleErrorsChanged(this->titleErrors);
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

const QVariantMap CreateContestForm::getMap() const {
    QVariantMap resultMap({{"title", title} });
    return resultMap;
}

bool CreateContestForm::isValid() const
{
    return titleErrors.isEmpty()
            && !title.isEmpty();
}

bool CreateContestForm::validate()
{
    validateTitle();
    return isValid();
}

void CreateContestForm::validateTitle()
{
    if (title.isEmpty()) {
        if (!titleErrors.contains("Введите название контеста")) {
            titleErrors.append(QString("Введите название контеста"));
            emit titleErrorsChanged(this->titleErrors);
        }
    } else {
        if (titleErrors.contains("Введите название контеста")) {
            titleErrors.removeOne("Введите название контеста");
            emit titleErrorsChanged(this->titleErrors);
        }
    }
}

void CreateContestForm::sendRequest() {
    if (isValid()) {
        Requester::instance()->sendRequest("users/login", nullptr, nullptr, Requester::Type::POST, getMap());
    }

//    Tester test;
//    test.sendRequestOnProblem(RegistrationController);
}
