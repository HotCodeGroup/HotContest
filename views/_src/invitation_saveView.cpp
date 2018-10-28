#include <QtCore>
#include <TreeFrogView>
#include "invitation.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT invitation_saveView : public TActionView
{
  Q_OBJECT
public:
  invitation_saveView() : TActionView() { }
  QString toString();
};

QString invitation_saveView::toString()
{
  responsebody.reserve(2160);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, invitation);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Invitation</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", invitation["invitationId"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Invitation ID<br /><input type=\"text\" name=\"invitation[invitationId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["invitationId"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>State<br /><input type=\"text\" name=\"invitation[state]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["state"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Sender ID<br /><input type=\"text\" name=\"invitation[senderId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["senderId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Addresse ID<br /><input type=\"text\" name=\"invitation[addresseId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["addresseId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Contest ID<br /><input type=\"text\" name=\"invitation[contestId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(invitation["contestId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", invitation["invitationId"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(invitation_saveView)

#include "invitation_saveView.moc"
