#include <QtCore>
#include <TreeFrogView>
#include "profile.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT profile_saveView : public TActionView
{
  Q_OBJECT
public:
  profile_saveView() : TActionView() { }
  QString toString();
};

QString profile_saveView::toString()
{
  responsebody.reserve(2728);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, profile);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Profile</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", profile["userId"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>User ID<br /><input type=\"text\" name=\"profile[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["userId"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>First Name<br /><input type=\"text\" name=\"profile[firstName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["firstName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Last Name<br /><input type=\"text\" name=\"profile[lastName]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["lastName"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Nickname<br /><input type=\"text\" name=\"profile[nickname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["nickname"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Email<br /><input type=\"text\" name=\"profile[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["email"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Password<br /><input type=\"text\" name=\"profile[password]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["password"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Date Joined<br /><input type=\"text\" name=\"profile[dateJoined]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["dateJoined"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Is Active<br /><input type=\"text\" name=\"profile[isActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(profile["isActive"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", profile["userId"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(profile_saveView)

#include "profile_saveView.moc"
