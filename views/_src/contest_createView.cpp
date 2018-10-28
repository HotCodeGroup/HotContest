#include <QtCore>
#include <TreeFrogView>
#include "contest.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT contest_createView : public TActionView
{
  Q_OBJECT
public:
  contest_createView() : TActionView() { }
  QString toString();
};

QString contest_createView::toString()
{
  responsebody.reserve(2067);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, contest);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Contest</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Title<br /><input name=\"contest[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["title"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Description<br /><input name=\"contest[description]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["description"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Start Time<br /><input name=\"contest[startTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["startTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Finish Time<br /><input name=\"contest[finishTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["finishTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Is Private<br /><input name=\"contest[isPrivate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["isPrivate"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Is Active<br /><input name=\"contest[isActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["isActive"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(contest_createView)

#include "contest_createView.moc"
