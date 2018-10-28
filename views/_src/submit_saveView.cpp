#include <QtCore>
#include <TreeFrogView>
#include "submit.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT submit_saveView : public TActionView
{
  Q_OBJECT
public:
  submit_saveView() : TActionView() { }
  QString toString();
};

QString submit_saveView::toString()
{
  responsebody.reserve(2286);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, submit);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Submit</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", submit["submitId"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Submit ID<br /><input type=\"text\" name=\"submit[submitId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["submitId"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Resp Code<br /><input type=\"text\" name=\"submit[respCode]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["respCode"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Error Test<br /><input type=\"text\" name=\"submit[errorTest]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["errorTest"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Time<br /><input type=\"text\" name=\"submit[time]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["time"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Memory<br /><input type=\"text\" name=\"submit[memory]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["memory"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Solution ID<br /><input type=\"text\" name=\"submit[solutionId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(submit["solutionId"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", submit["submitId"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(submit_saveView)

#include "submit_saveView.moc"
