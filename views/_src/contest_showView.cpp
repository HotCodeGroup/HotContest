#include <QtCore>
#include <TreeFrogView>
#include "contest.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT contest_showView : public TActionView
{
  Q_OBJECT
public:
  contest_showView() : TActionView() { }
  QString toString();
};

QString contest_showView::toString()
{
  responsebody.reserve(1905);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Contest, contest);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Contest</h1>\n<dt>Contest ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.contestId());
  responsebody += QLatin1String("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.title());
  responsebody += QLatin1String("</dd><br />\n<dt>Description</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.description());
  responsebody += QLatin1String("</dd><br />\n<dt>Start Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.startTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Finish Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.finishTime());
  responsebody += QLatin1String("</dd><br />\n<dt>Is Private</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.isPrivate());
  responsebody += QLatin1String("</dd><br />\n<dt>Is Active</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.isActive());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contest.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", contest.contestId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(contest_showView)

#include "contest_showView.moc"
