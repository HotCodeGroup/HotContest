#include <QtCore>
#include <TreeFrogView>
#include "message.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT message_saveView : public TActionView
{
  Q_OBJECT
public:
  message_saveView() : TActionView() { }
  QString toString();
};

QString message_saveView::toString()
{
  responsebody.reserve(2097);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, message);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Message</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", message["messageId"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Message ID<br /><input type=\"text\" name=\"message[messageId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["messageId"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Text<br /><input type=\"text\" name=\"message[text]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["text"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Time Stamp<br /><input type=\"text\" name=\"message[timeStamp]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["timeStamp"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Author ID<br /><input type=\"text\" name=\"message[authorId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["authorId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Contest ID<br /><input type=\"text\" name=\"message[contestId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(message["contestId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", message["messageId"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(message_saveView)

#include "message_saveView.moc"
