#include <QtCore>
#include <TreeFrogView>
#include "test.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT test_saveView : public TActionView
{
  Q_OBJECT
public:
  test_saveView() : TActionView() { }
  QString toString();
};

QString test_saveView::toString()
{
  responsebody.reserve(1825);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, test);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Test</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", test["testId"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Test ID<br /><input type=\"text\" name=\"test[testId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(test["testId"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Input<br /><input type=\"text\" name=\"test[input]\" value=\"");
  responsebody += THttpUtility::htmlEscape(test["input"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Output<br /><input type=\"text\" name=\"test[output]\" value=\"");
  responsebody += THttpUtility::htmlEscape(test["output"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Problem ID<br /><input type=\"text\" name=\"test[problemId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(test["problemId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", test["testId"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(test_saveView)

#include "test_saveView.moc"
