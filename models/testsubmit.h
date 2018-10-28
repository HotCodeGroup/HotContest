#ifndef TESTSUBMIT_H
#define TESTSUBMIT_H

#include <QObject>
#include <QString>
#include <QDateTime>

class TestSubmit : public QObject {

    Q_OBJECT
//    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
//    Q_PROPERTY(const QString& verdict READ getVerdict WRITE setVerdict NOTIFY verdictChanged)
//    Q_PROPERTY(const QString& memory READ getMemory WRITE setMemory NOTIFY memoryChanged)
//    Q_PROPERTY(const QString& time READ getTime WRITE setTime NOTIFY timeChanged)

public:
    TestSubmit(int id = 0, const QString& verdict = "",
               const QString& memory = "", const QString& time = "");
    ~TestSubmit();

    int getId() const;
    void setId(int id);

    const QString& getVerdict() const;
    void setVerdict(const QString& verdict);

    const QString& getMemory() const;
    void setMemory(const QString& memory);

    const QString& getTime() const;
    void setTime(const QString& time);

private:
    int id;
    QString verdict;
    QString memory;
    QString time;
};

#endif // TESTSUBMIT_H
