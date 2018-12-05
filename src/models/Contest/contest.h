#ifndef CONTEST_H
#define CONTEST_H

#include <QString>
#include <QDateTime>
#include <QJsonObject>
#include <QObject>
#include <QJsonValue>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class Contest: public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(const QString& description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(const QString& startTime READ getStartTime WRITE setStartTime NOTIFY startTimeChanged)
    Q_PROPERTY(const QString& finishTime READ getFinishTime WRITE setFinishTime NOTIFY finishTimeChanged)
    Q_PROPERTY(bool isPrivate READ getIsPrivate WRITE setIsPrivate NOTIFY isPrivateChanged)
    Q_PROPERTY(StateInfo* state READ getState NOTIFY stateChanged)

public:
    static Contest* instance();
    ~Contest();

    int getId() const;
    void setId(int id);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    const QString& getDescription() const;
    void setDescription(const QString& description);

    const QString& getStartTime() const;
    void setStartTime(const QString& startTime);

    const QString& getFinishTime() const;
    void setFinishTime(const QString& finishTime);

    bool getIsPrivate() const;
    void setIsPrivate(bool value);

    const QDateTime& getDTStartTime() const;
    void setDTStartTime(const QDateTime& startTime);

    const QDateTime& getDTFinishTime() const;
    void setDTFinishTime(const QDateTime& finishTime);

    StateInfo* getState() const;

    Q_INVOKABLE static void sendRequest(int contestId);

signals:
    void idChanged(int);
    void titleChanged(const QString&);
    void descriptionChanged(const QString&);
    void startTimeChanged(const QString&);
    void finishTimeChanged(const QString&);
    void isPrivateChanged(bool);

    void stateChanged(StateInfo*);

private:
    static Contest* p_instance;
    Contest(int id = 0, const QString& title = "",
            const QString& description = "", bool isPrivate = false);

    static void ContestController(const QJsonObject &obj);

    int id;
    QString title;
    QString description;
    QString startTime;
    QString finishTime;
    bool isPrivate;

    StateInfo* state;
    QDateTime DTstartTime;
    QDateTime DTfinishTime;
};

#endif // CONTEST_H
