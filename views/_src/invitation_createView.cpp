#include <QtCore>
#include <TreeFrogView>
#include "invitation.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT invitation_createView : public TActionView
{
  Q_OBJECT
public:
  invitation_createView() : TActionView() { }
  QString toString();
};

QString invitation_createView::toString()
{
  responsebody.reserve(1686);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, invitation);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Invitation</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>State<br /><input name=\"invitation[state]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["state"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Sender ID<br /><input name=\"invitation[senderId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["senderId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Addresse ID<br /><input name=\"invitation[addresseId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["addresseId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Contest ID<br /><input name=\"invitation[contestId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["contestId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(invitation_createView)

#include "invitation_createView.moc"
