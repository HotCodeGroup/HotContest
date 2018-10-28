#include <QtCore>
#include <TreeFrogView>
#include "message.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT message_createView : public TActionView
{
  Q_OBJECT
public:
  message_createView() : TActionView() { }
  QString toString();
};

QString message_createView::toString()
{
  responsebody.reserve(1650);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, message);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Message</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Text<br /><input name=\"message[text]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["text"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Time Stamp<br /><input name=\"message[timeStamp]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["timeStamp"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Author ID<br /><input name=\"message[authorId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["authorId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Contest ID<br /><input name=\"message[contestId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["contestId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(message_createView)

#include "message_createView.moc"
