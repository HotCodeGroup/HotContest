#include <QtCore>
#include <TreeFrogView>
#include "submit.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT submit_createView : public TActionView
{
  Q_OBJECT
public:
  submit_createView() : TActionView() { }
  QString toString();
};

QString submit_createView::toString()
{
  responsebody.reserve(1834);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, submit);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Submit</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Resp Code<br /><input name=\"submit[respCode]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["respCode"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Error Test<br /><input name=\"submit[errorTest]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["errorTest"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Time<br /><input name=\"submit[time]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["time"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memory<br /><input name=\"submit[memory]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["memory"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Solution ID<br /><input name=\"submit[solutionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["solutionId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(submit_createView)

#include "submit_createView.moc"
