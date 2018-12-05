#include "profilecontroller.h"
#include "profile.h"
#include "profilevalidator.h"
#include "profileeditvalidator.h"

/* Users / User / View a User Account Detail
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/user/view-a-user-account-detail
 *
 */
void ProfileController::details(const QString &userId)
{
    bool ok = false;
    int userIntID = userId.toInt(&ok);
    if (!ok) {
        renderJson(QJsonObject());
    }

    auto profileVariantMap = Profile::get(userIntID).toVariantMapLight();
    if (profileVariantMap["userId"] == 0) {
        renderJson(QJsonObject());
    }

    renderJson(profileVariantMap);
}

/* Users / Registration / Register
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/registration/register
 *
 */
void ProfileController::signup()
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto signUpData = httpRequest().jsonData().object().toVariantMap();

    ProfileValidator validator;
    if (!validator.validate(signUpData)) {
        renderJson(QJsonArray::fromStringList(validator.errorMessages()));
        return;
    }

    QJsonArray errorsArray;
    auto model = Profile::create(signUpData);
    if (model.isNull()) {
        errorsArray.push_back(QJsonValue(tr("Ошибка сохранения")));
    }

    renderJson(errorsArray);
}

/* Users / User / Edit a User Account
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/user/edit-a-user-account
 *
 *
 * todo: реализовать нормально, когда будут сессии
 */
void ProfileController::edit(const QString &userId)
{
    if (httpRequest().method() != Tf::Put) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    QJsonArray errorsArray;
    bool ok = false;
    int userIntID = userId.toInt(&ok);
    if (!ok) {
        errorsArray.push_back("Wrong user ID!");
        renderJson(errorsArray);
        return;
    }

    auto model = Profile::get(userIntID);
    if (model.isNull()) {
        errorsArray.push_back("Original data not found!");
        renderJson(errorsArray);
        return;
    }

    auto editData = httpRequest().jsonData().object().toVariantMap();
    ProfileEditValidator validator;
    if (!validator.validate(editData)) {
        renderJson(QJsonArray::fromStringList(validator.errorMessages()));
        return;
    }

    model.updateProperties(editData);
    if (!model.save()) {
        errorsArray.push_back("Failed to update!");
    }

    renderJson(errorsArray);
    return;
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ProfileController)
