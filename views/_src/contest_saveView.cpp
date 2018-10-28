#include <QtCore>
#include <TreeFrogView>
#include "contest.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT contest_saveView : public TActionView
{
  Q_OBJECT
public:
  contest_saveView() : TActionView() { }
  QString toString();
};

QString contest_saveView::toString()
{
  responsebody.reserve(2542);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, contest);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Contest</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", contest["contestId"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Contest ID<br /><input type=\"text\" name=\"contest[contestId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["contestId"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Title<br /><input type=\"text\" name=\"contest[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["title"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Description<br /><input type=\"text\" name=\"contest[description]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["description"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Start Time<br /><input type=\"text\" name=\"contest[startTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["startTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Finish Time<br /><input type=\"text\" name=\"contest[finishTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["finishTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Is Private<br /><input type=\"text\" name=\"contest[isPrivate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["isPrivate"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Is Active<br /><input type=\"text\" name=\"contest[isActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contest["isActive"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", contest["contestId"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(contest_saveView)

#include "contest_saveView.moc"
