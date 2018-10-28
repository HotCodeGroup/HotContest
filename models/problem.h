#ifndef PROBLEM_H
#define PROBLEM_H

#include <QString>
#include <QObject>

class Problem : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(const QString& description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(const QString& timeLimit READ getTimeLimit WRITE setTimeLimit NOTIFY timeLimitChanged)
    Q_PROPERTY(const QString& memLimit READ getMemLimit WRITE setMemLimit NOTIFY memLimitChanged)
    Q_PROPERTY(int triesLeft READ getTriesLeft WRITE setTriesLeft NOTIFY triesLeftChanged)
    Q_PROPERTY(int penaltyTry READ getPenaltyTry WRITE setPenaltyTry NOTIFY penaltyTryChanged)
    Q_PROPERTY(int penaltyTime READ grtPenaltyTime WRITE setPenaltyTime NOTIFY penaltyTimeChanged)

public:
    Problem(int id = 0, const QString& title = "",
            const QString& description = "", const QString& timeLimit = "",
            const QString& memLimit = "", int triesLeft = 0,
            int penaltyTry = 0, int penaltyTime = 0);
    ~Problem();

    int getId() const;
    void setId(int id);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    const QString& getDescription() const;
    void setDescription(const QString& description);

    const QString& getTimeLimit() const;
    void setTimeLimit(const QString& timeLimit);

    const QString& getMemLimit() const;
    void setMemLimit(const QString& memLimit);

    int getTriesLeft() const;
    void setTriesLeft(int triesLeft);

    int getPenaltyTry() const;
    void setPenaltyTry(int penaltyTry);

    int getPenaltyTime() const;
    void setPenaltyTime(int penaltyTime);

signals:
    void idChanged(int);
    void titleChanged(const QString&);
    void descriptionChanged(const QString&);
    void timeLimitChanged(const QString&);
    void memLimitChanged(const QString&);
    void triesLeftChanged(int);
    void penaltyTryChanged(int);
    void penaltyTimeChanged(int);

private:
    int id;
    QString title;
    QString description;
    QString timeLimit;
    QString memLimit;
    int triesLeft;
    int penaltyTry;
    int penaltyTime;
};

#endif // PROBLEM_H
