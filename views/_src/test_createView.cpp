#include <QtCore>
#include <TreeFrogView>
#include "test.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT test_createView : public TActionView
{
  Q_OBJECT
public:
  test_createView() : TActionView() { }
  QString toString();
};

QString test_createView::toString()
{
  responsebody.reserve(1419);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, test);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Test</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Input<br /><input name=\"test[input]\" value=\"");
  responsebody += THttpUtility::htmlEscape(test["input"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Output<br /><input name=\"test[output]\" value=\"");
  responsebody += THttpUtility::htmlEscape(test["output"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Problem ID<br /><input name=\"test[problemId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(test["problemId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(test_createView)

#include "test_createView.moc"
