#ifndef CONTEST_H
#define CONTEST_H

#include <QString>
#include <QDateTime>
#include <QObject>

class Contest: public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(const Qstring& description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(const QDateTime& startTime READ getStartTime WRITE setStartTime NOTIFY startTimeChanged)
    Q_PROPERTY(const QDateTime& finishTime READ getFinishTime WRITE setFinishTime NOTIFY finishTimeChanged)
    Q_PROPERTY(bool isPrivate READ getisPrivate WRITE setIsPrivate NOTIFY isPrivateChanged)

public:
    Contest(int id = 0, const QString& title = "",
            const QString& description = "", const QDateTime& startTime,
            const QDateTime& finishTime, bool isPrivate = false);
    ~Contest();

    int getId() const;
    void setId(int id);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    const QString& getDescription() const;
    void setDescription(const QString& description);

    const QDateTime& getStartTime() const;
    void setStartTime(const QDateTime& startTime);

    const QDateTime& getFinishTime() const;
    void setFinishTime(const QDateTime& finishTime);

    bool getIsPrivate() const;
    void setIsPrivate(bool value);

signals:
    void idChanged(int);
    void titleChanged(const QString&);
    void descriptionChanged(const QString&);
    void startTimeChanged(const QDateTime&);
    void finishTimeChanged(const QDateTime&);
    void isPrivateChanged(bool);

private:
    int id;
    QString title;
    QString description;
    QDateTime startTime;
    QDateTime finishTime;
    bool isPrivate;
};

#endif // CONTEST_H
