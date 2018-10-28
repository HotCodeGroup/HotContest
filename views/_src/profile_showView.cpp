#include <QtCore>
#include <TreeFrogView>
#include "profile.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT profile_showView : public TActionView
{
  Q_OBJECT
public:
  profile_showView() : TActionView() { }
  QString toString();
};

QString profile_showView::toString()
{
  responsebody.reserve(2023);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Profile, profile);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Profile</h1>\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>First Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.firstName());
  responsebody += QLatin1String("</dd><br />\n<dt>Last Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.lastName());
  responsebody += QLatin1String("</dd><br />\n<dt>Nickname</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.nickname());
  responsebody += QLatin1String("</dd><br />\n<dt>Email</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.email());
  responsebody += QLatin1String("</dd><br />\n<dt>Password</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.password());
  responsebody += QLatin1String("</dd><br />\n<dt>Date Joined</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.dateJoined());
  responsebody += QLatin1String("</dd><br />\n<dt>Is Active</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.isActive());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(profile.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", profile.userId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(profile_showView)

#include "profile_showView.moc"
