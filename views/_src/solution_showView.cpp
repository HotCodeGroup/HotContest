#include <QtCore>
#include <TreeFrogView>
#include "solution.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT solution_showView : public TActionView
{
  Q_OBJECT
public:
  solution_showView() : TActionView() { }
  QString toString();
};

QString solution_showView::toString()
{
  responsebody.reserve(1640);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Solution, solution);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Solution</h1>\n<dt>Solution ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(solution.solutionId());
  responsebody += QLatin1String("</dd><br />\n<dt>Src File</dt><dd>");
  responsebody += THttpUtility::htmlEscape(solution.srcFile());
  responsebody += QLatin1String("</dd><br />\n<dt>Submit Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(solution.submitTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Problem ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(solution.problemId());
  responsebody += QLatin1String("</dd><br />\n<dt>User ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(solution.userId());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(solution.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", solution.solutionId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(solution_showView)

#include "solution_showView.moc"
