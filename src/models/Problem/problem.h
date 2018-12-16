#ifndef PROBLEM_H
#define PROBLEM_H

#include <QString>
#include <QJsonObject>
#include <QObject>
#include <QJsonValue>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class Problem : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(const QString& description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(int timeLimit READ getTimeLimit WRITE setTimeLimit NOTIFY timeLimitChanged)
    Q_PROPERTY(int memLimit READ getMemLimit WRITE setMemLimit NOTIFY memLimitChanged)
    Q_PROPERTY(int triesLeft READ getTriesLeft WRITE setTriesLeft NOTIFY triesLeftChanged)
    Q_PROPERTY(int penaltyTry READ getPenaltyTry WRITE setPenaltyTry NOTIFY penaltyTryChanged)
    Q_PROPERTY(int penaltyTime READ getPenaltyTime WRITE setPenaltyTime NOTIFY penaltyTimeChanged)
    Q_PROPERTY(int points READ getPoints WRITE setPoints NOTIFY pointsChanged)
    Q_PROPERTY(StateInfo* state READ getState NOTIFY stateChanged)

public:
    static Problem* instance();
    ~Problem();

    int getId() const;
    void setId(int id);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    const QString& getDescription() const;
    void setDescription(const QString& description);

    int getTimeLimit() const;
    void setTimeLimit(int timeLimit);

    int getMemLimit() const;
    void setMemLimit(int memLimit);

    int getTriesLeft() const;
    void setTriesLeft(int triesLeft);

    int getPenaltyTry() const;
    void setPenaltyTry(int penaltyTry);

    int getPenaltyTime() const;
    void setPenaltyTime(int penaltyTime);

    int getPoints() const;
    void setPoints(int points);

    StateInfo* getState() const;

    Q_INVOKABLE static void sendRequest(int contestId, int problemId);

signals:
    void idChanged(int);
    void titleChanged(const QString&);
    void descriptionChanged(const QString&);
    void timeLimitChanged(int);
    void memLimitChanged(int);
    void triesLeftChanged(int);
    void penaltyTryChanged(int);
    void penaltyTimeChanged(int);
    void pointsChanged(int);

    void stateChanged(StateInfo*);

private:
    static Problem* p_instance;
    Problem(int id = 0, const QString& title = "",
            const QString& description = "", int timeLimit = 0,
            int memLimit = 0, int triesLeft = 0,
            int penaltyTry = 0, int penaltyTime = 0,
            int points = 0);


    static void ProblemController(const QJsonObject &obj);

    int id;
    QString title;
    QString description;
    int timeLimit;
    int memLimit;
    int triesLeft;
    int penaltyTry;
    int penaltyTime;
    int points;

    StateInfo* state;
};

#endif // PROBLEM_H
