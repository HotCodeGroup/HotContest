#ifndef CREATECONTESTFORM_H
#define CREATECONTESTFORM_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QVariantMap>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class CreateContestForm : public QObject {

    Q_OBJECT
    Q_PROPERTY(const QString& title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(const QVector<QString>& titleErrors READ getTitleErrors WRITE setTitleErrors NOTIFY titleErrorsChanged)
    Q_PROPERTY(bool isValid READ isValid NOTIFY isValidChanged)

public:
    CreateContestForm(const QString& title = "");
    ~CreateContestForm();

    const QString& getTitle() const;
    void setTitle(const QString& title);

    QVector<QString>& getTitleErrors();
    void setTitleErrors(const QVector<QString>& titleErrors);

    const QVariantMap getMap() const;
    bool isValid() const;

    Q_INVOKABLE bool validate();
    Q_INVOKABLE void sendRequest();

signals:
    void titleChanged(const QString&);
    void titleErrorsChanged(const QVector<QString>&);
    void isValidChanged(bool);

protected:
    void validateTitle();

    static void CreateContestController(const QJsonObject &obj);

    QString title;
    QVector<QString> titleErrors;
};

#endif // CREATECONTESTFORM_H
