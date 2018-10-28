#include <QtCore>
#include <TreeFrogView>
#include "solution.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT solution_saveView : public TActionView
{
  Q_OBJECT
public:
  solution_saveView() : TActionView() { }
  QString toString();
};

QString solution_saveView::toString()
{
  responsebody.reserve(2123);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, solution);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Solution</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", solution["solutionId"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Solution ID<br /><input type=\"text\" name=\"solution[solutionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(solution["solutionId"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Src File<br /><input type=\"text\" name=\"solution[srcFile]\" value=\"");
  responsebody += THttpUtility::htmlEscape(solution["srcFile"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Submit Time<br /><input type=\"text\" name=\"solution[submitTime]\" value=\"");
  responsebody += THttpUtility::htmlEscape(solution["submitTime"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Problem ID<br /><input type=\"text\" name=\"solution[problemId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(solution["problemId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>User ID<br /><input type=\"text\" name=\"solution[userId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(solution["userId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", solution["solutionId"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(solution_saveView)

#include "solution_saveView.moc"
