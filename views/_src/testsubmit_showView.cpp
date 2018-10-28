#include <QtCore>
#include <TreeFrogView>
#include "testsubmit.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT testsubmit_showView : public TActionView
{
  Q_OBJECT
public:
  testsubmit_showView() : TActionView() { }
  QString toString();
};

QString testsubmit_showView::toString()
{
  responsebody.reserve(1786);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(TestSubmit, testSubmit);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Test Submit</h1>\n<dt>Test Submit ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(testSubmit.testSubmitId());
  responsebody += QLatin1String("</dd><br />\n<dt>Verdict</dt><dd>");
  responsebody += THttpUtility::htmlEscape(testSubmit.verdict());
  responsebody += QLatin1String("</dd><br />\n<dt>Time</dt><dd>");
  responsebody += THttpUtility::htmlEscape(testSubmit.time());
  responsebody += QLatin1String("</dd><br />\n<dt>Memory</dt><dd>");
  responsebody += THttpUtility::htmlEscape(testSubmit.memory());
  responsebody += QLatin1String("</dd><br />\n<dt>Test ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(testSubmit.testId());
  responsebody += QLatin1String("</dd><br />\n<dt>Submit ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(testSubmit.submitId());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(testSubmit.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", testSubmit.testSubmitId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(testsubmit_showView)

#include "testsubmit_showView.moc"
