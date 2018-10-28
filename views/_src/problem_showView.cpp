#include <QtCore>
#include <TreeFrogView>
#include "problem.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT problem_showView : public TActionView
{
  Q_OBJECT
public:
  problem_showView() : TActionView() { }
  QString toString();
};

QString problem_showView::toString()
{
  responsebody.reserve(2322);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Problem, problem);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Problem</h1>\n<dt>Problem ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.problemId());
  responsebody += QLatin1String("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.title());
  responsebody += QLatin1String("</dd><br />\n<dt>Description</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.description());
  responsebody += QLatin1String("</dd><br />\n<dt>Time Limit</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.timeLimit());
  responsebody += QLatin1String("</dd><br />\n<dt>Memory Limit</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.memoryLimit());
  responsebody += QLatin1String("</dd><br />\n<dt>Tries Left</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.triesLeft());
  responsebody += QLatin1String("</dd><br />\n<dt>Points</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.points());
  responsebody += QLatin1String("</dd><br />\n<dt>Penalty Try</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.penaltyTry());
  responsebody += QLatin1String("</dd><br />\n<dt>Penalty Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.penaltyTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Contest ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.contestId());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(problem.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", problem.problemId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(problem_showView)

#include "problem_showView.moc"
