#include "usercontroller.h"
#include "profile.h"

/* Users / Login / Login
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/login/login
 *
 */
void UserController::login()
{
    auto loginData = httpRequest().jsonData().object();

    QString username = loginData["login"].toString();
    QString password = loginData["password"].toString();

    Profile user = Profile::authenticate(username, password);
    QJsonArray errorsArray;

    if (!user.isNull()) {
        userLogin(&user);
    } else {
        errorsArray.push_back(QJsonValue(tr("Логин и пароль не совпадают!")));
    }

    renderJson(errorsArray);
}

/* Users / Logout / Logout
 *
 * Doc url:
 * https://hotcode.docs.apiary.io/#reference/users/user/logout
 *
 */
void UserController::logout()
{
    userLogout();   //DUP пока не обрабатывается
    renderErrorResponse(204); //неудачное название
}

// Don't remove below this line
T_DEFINE_CONTROLLER(UserController)
