#ifndef SUBMIT_H
#define SUBMIT_H

#include <QObject>
#include <QString>
#include <QDateTime>

class Submit : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& submitTime READ getSubmitTime WRITE setSubmitTime NOTIFY submitTimeChanged)
    Q_PROPERTY(int problem READ getProblem WRITE setProblem NOTIFY problemChanged)
    Q_PROPERTY(int respCode READ getRespCode WRITE setRespCode NOTIFY respCodeChanged)
    Q_PROPERTY(int memory READ getMemory WRITE setMemory NOTIFY memoryChanged)
    Q_PROPERTY(int time READ getTime WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(int errorTest READ getErrorTest WRITE setErrorTest NOTIFY errorTestChanged)
    Q_PROPERTY(int points READ getPoints WRITE setPoints NOTIFY pointsChanged)

public:
    Submit(int id = 0, const QString& submitTime = "", int problem = 0,
           int respCode = 0, int memory = 0,
           int time = 0,  int errorTest = 0, int points = 0);
    ~Submit();

    int getId() const;
    void setId(int id);

    const QString& getSubmitTime() const;
    void setSubmitTime(const QString& submitTime);

    int getProblem() const;
    void setProblem(int problem);

    int getRespCode() const;
    void setRespCode(int respCode);

    int getMemory() const;
    void setMemory(int memory);

    int getTime() const;
    void setTime(int time);

    int getErrorTest() const;
    void setErrorTest(int errorTest);

    int getPoints() const;
    void setPoints(int points);

    const QDateTime& getDTSubmitTime() const;
    void setDTSubmitTime(const QDateTime& submitTime);

signals:
    void idChanged(int);
    void submitTimeChanged(const QString&);
    void problemChanged(int);
    void respCodeChanged(int);
    void memoryChanged(int);
    void timeChanged(int);
    void errorTestChanged(int);
    void pointsChanged(int);

private:
    int id;
    QString submitTime;
    int problem;
    int respCode;
    int memory;
    int time;
    int errorTest;
    int points;

    QDateTime DTsubmitTime;
};

#endif // SUBMIT_H
