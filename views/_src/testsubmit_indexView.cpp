#include <QtCore>
#include <TreeFrogView>
#include "testsubmit.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT testsubmit_indexView : public TActionView
{
  Q_OBJECT
public:
  testsubmit_indexView() : TActionView() { }
  QString toString();
};

QString testsubmit_indexView::toString()
{
  responsebody.reserve(2076);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>Listing Test Submit</h1>\n\n");
  responsebody += QVariant(linkTo("Create a new Test Submit", urla("create"))).toString();
  responsebody += QLatin1String("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>Test Submit ID</th>\n    <th>Verdict</th>\n    <th>Time</th>\n    <th>Memory</th>\n    <th>Test ID</th>\n    <th>Submit ID</th>\n  </tr>\n");
  tfetch(QList<TestSubmit>, testSubmitList);
  for (const auto &i : testSubmitList) {
  responsebody += QLatin1String("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.testSubmitId());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.verdict());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.time());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.memory());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.testId());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.submitId());
  responsebody += QLatin1String("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.testSubmitId()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("save", i.testSubmitId()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.testSubmitId()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QLatin1String("\n    </td>\n  </tr>\n");
  };
  responsebody += QLatin1String("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(testsubmit_indexView)

#include "testsubmit_indexView.moc"
