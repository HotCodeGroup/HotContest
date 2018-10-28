#include <QtCore>
#include <TreeFrogView>
#include "submit.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT submit_showView : public TActionView
{
  Q_OBJECT
public:
  submit_showView() : TActionView() { }
  QString toString();
};

QString submit_showView::toString()
{
  responsebody.reserve(1741);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Submit, submit);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Submit</h1>\n<dt>Submit ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(submit.submitId());
  responsebody += QLatin1String("</dd><br />\n<dt>Resp Code</dt><dd>");
  responsebody += THttpUtility::htmlEscape(submit.respCode());
  responsebody += QLatin1String("</dd><br />\n<dt>Error Test</dt><dd>");
  responsebody += THttpUtility::htmlEscape(submit.errorTest());
  responsebody += QLatin1String("</dd><br />\n<dt>Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(submit.time());
  responsebody += QLatin1String("</dd><br />\n<dt>Memory</dt><dd>");
  responsebody += THttpUtility::htmlEscape(submit.memory());
  responsebody += QLatin1String("</dd><br />\n<dt>Solution ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(submit.solutionId());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(submit.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", submit.submitId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(submit_showView)

#include "submit_showView.moc"
