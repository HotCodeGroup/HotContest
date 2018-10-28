#include <QtCore>
#include <TreeFrogView>
#include "test.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT test_showView : public TActionView
{
  Q_OBJECT
public:
  test_showView() : TActionView() { }
  QString toString();
};

QString test_showView::toString()
{
  responsebody.reserve(1445);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Test, test);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Test</h1>\n<dt>Test ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(test.testId());
  responsebody += QLatin1String("</dd><br />\n<dt>Input</dt><dd>");
  responsebody += THttpUtility::htmlEscape(test.input());
  responsebody += QLatin1String("</dd><br />\n<dt>Output</dt><dd>");
  responsebody += THttpUtility::htmlEscape(test.output());
  responsebody += QLatin1String("</dd><br />\n<dt>Problem ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(test.problemId());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(test.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", test.testId()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(test_showView)

#include "test_showView.moc"
