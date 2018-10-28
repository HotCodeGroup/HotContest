#include <QtCore>
#include <TreeFrogView>
#include "problem.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT problem_createView : public TActionView
{
  Q_OBJECT
public:
  problem_createView() : TActionView() { }
  QString toString();
};

QString problem_createView::toString()
{
  responsebody.reserve(2681);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, problem);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Problem</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Title<br /><input name=\"problem[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["title"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Description<br /><input name=\"problem[description]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["description"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Time Limit<br /><input name=\"problem[timeLimit]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["timeLimit"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memory Limit<br /><input name=\"problem[memoryLimit]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["memoryLimit"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Tries Left<br /><input name=\"problem[triesLeft]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["triesLeft"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Points<br /><input name=\"problem[points]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["points"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Penalty Try<br /><input name=\"problem[penaltyTry]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["penaltyTry"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Penalty Time<br /><input name=\"problem[penaltyTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["penaltyTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Contest ID<br /><input name=\"problem[contestId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(problem["contestId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(problem_createView)

#include "problem_createView.moc"
