#include <QtCore>
#include <TreeFrogView>
#include "message.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT message_showView : public TActionView
{
  Q_OBJECT
public:
  message_showView() : TActionView() { }
  QString toString();
};

QString message_showView::toString()
{
  responsebody.reserve(1622);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Message, message);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Message</h1>\n<dt>Message ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(message.messageId());
  responsebody += QLatin1String("</dd><br />\n<dt>Text</dt><dd>");
  responsebody += THttpUtility::htmlEscape(message.text());
  responsebody += QLatin1String("</dd><br />\n<dt>Time Stamp</dt><dd>");
  responsebody += THttpUtility::htmlEscape(message.timeStamp());
  responsebody += QLatin1String("</dd><br />\n<dt>Author ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(message.authorId());
  responsebody += QLatin1String("</dd><br />\n<dt>Contest ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(message.contestId());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(message.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", message.messageId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(message_showView)

#include "message_showView.moc"
