#ifndef SUBMIT_H
#define SUBMIT_H

#include <QObject>
#include <QString>
#include <QDateTime>

class Submit : public QObject {

    Q_OBJECT
//    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
//    Q_PROPERTY(const QDateTime& submitTime READ getSubmitTime WRITE setSubmitTime NOTIFY submitTimeChanged)
//    Q_PROPERTY(const QString& problem READ getProblem WRITE setProblem NOTIFY problemChanged)
//    Q_PROPERTY(const QString& respCode READ getRespCode WRITE setRespCode NOTIFY respCodeChanged)
//    Q_PROPERTY(const QString& memory READ getMemory WRITE setMemory NOTIFY memoryChanged)
//    Q_PROPERTY(const QString& time READ getTime WRITE setTime NOTIFY timeChanged)
//    Q_PROPERTY(int errorTest READ getErrorTest WRITE setErrorTest NOTIFY errorTestChanged)
//    Q_PROPERTY(int points READ getPoints WRITE setPoints NOTIFY pointsChanged)

public:
    Submit(int id = 0, const QDateTime& submitTime, const QString& problem = "",
           const QString& respCode = "", const QString& memory = "",
           const QString& time = "",  int errorTest = 0, int points = 0);
    ~Submit();

    int getId() const;
    void setId(int id);

    const QDateTime& getSubmitTime() const;
    void setSubmitTime(const QDateTime& submitTime);

    const QString& getProblem() const;
    void setProblem(const QString& problem);

    const QString& getRespCode() const;
    void setRespCode(const QString& respCode);

    const QString& getMemory() const;
    void setMemory(const QString& memory);

    const QString& getTime() const;
    void setTime(const QString& time);

    int getErrorTest() const;
    void setErrorTest(int errorTest);

    int getPoints() const;
    void setPoints(int points);

//signals:
//    void idChanged(int);
//    void submitTimeChanged(const QDateTime&);
//    void problemChanged(const QString&);
//    void respCodeChanged(const QString&);
//    void memoryChanged(const QString&);
//    void timeChanged(const QString&);
//    void errorTestChanged(int);
//    void pointsChanged(int);

private:
    int id;
    QDateTime submitTime;
    QString problem;
    QString respCode;
    QString memory;
    QString time;
    int errorTest;
    int points;
};

#endif // SUBMIT_H
