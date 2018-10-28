#include <QtCore>
#include <TreeFrogView>
#include "invitation.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT invitation_showView : public TActionView
{
  Q_OBJECT
public:
  invitation_showView() : TActionView() { }
  QString toString();
};

QString invitation_showView::toString()
{
  responsebody.reserve(1665);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Invitation, invitation);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Invitation</h1>\n<dt>Invitation ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(invitation.invitationId());
  responsebody += QLatin1String("</dd><br />\n<dt>State</dt><dd>");
  responsebody += THttpUtility::htmlEscape(invitation.state());
  responsebody += QLatin1String("</dd><br />\n<dt>Sender ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(invitation.senderId());
  responsebody += QLatin1String("</dd><br />\n<dt>Addresse ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(invitation.addresseId());
  responsebody += QLatin1String("</dd><br />\n<dt>Contest ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(invitation.contestId());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(invitation.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", invitation.invitationId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(invitation_showView)

#include "invitation_showView.moc"
