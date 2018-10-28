#include <QtCore>
#include <TreeFrogView>
#include "profile.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT profile_createView : public TActionView
{
  Q_OBJECT
public:
  profile_createView() : TActionView() { }
  QString toString();
};

QString profile_createView::toString()
{
  responsebody.reserve(2254);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, profile);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Profile</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>First Name<br /><input name=\"profile[firstName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["firstName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Last Name<br /><input name=\"profile[lastName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["lastName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Nickname<br /><input name=\"profile[nickname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["nickname"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Email<br /><input name=\"profile[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["email"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Password<br /><input name=\"profile[password]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["password"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Date Joined<br /><input name=\"profile[dateJoined]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["dateJoined"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Is Active<br /><input name=\"profile[isActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["isActive"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(profile_createView)

#include "profile_createView.moc"
