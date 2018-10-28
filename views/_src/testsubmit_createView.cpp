#include <QtCore>
#include <TreeFrogView>
#include "testsubmit.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT testsubmit_createView : public TActionView
{
  Q_OBJECT
public:
  testsubmit_createView() : TActionView() { }
  QString toString();
};

QString testsubmit_createView::toString()
{
  responsebody.reserve(1864);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, testSubmit);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Test Submit</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Verdict<br /><input name=\"testSubmit[verdict]\" value=\"");
  responsebody += THttpUtility::htmlEscape(testSubmit["verdict"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Time<br /><input name=\"testSubmit[time]\" value=\"");
  responsebody += THttpUtility::htmlEscape(testSubmit["time"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memory<br /><input name=\"testSubmit[memory]\" value=\"");
  responsebody += THttpUtility::htmlEscape(testSubmit["memory"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Test ID<br /><input name=\"testSubmit[testId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(testSubmit["testId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Submit ID<br /><input name=\"testSubmit[submitId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(testSubmit["submitId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(testsubmit_createView)

#include "testsubmit_createView.moc"
