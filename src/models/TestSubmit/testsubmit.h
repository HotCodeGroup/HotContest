#ifndef TESTSUBMIT_H
#define TESTSUBMIT_H

#include <QObject>
#include <QString>
#include <QDateTime>

class TestSubmit : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int verdict READ getVerdict WRITE setVerdict NOTIFY verdictChanged)
    Q_PROPERTY(int memory READ getMemory WRITE setMemory NOTIFY memoryChanged)
    Q_PROPERTY(int time READ getTime WRITE setTime NOTIFY timeChanged)

public:
    TestSubmit(int id = 0, int verdict = 0,
               int memory = 0, int time = 0);
    ~TestSubmit();

    int getId() const;
    void setId(int id);

    int getVerdict() const;
    void setVerdict(int verdict);

    int getMemory() const;
    void setMemory(int memory);

    int getTime() const;
    void setTime(int time);

signals:
    void idChanged(int);
    void verdictChanged(int);
    void memoryChanged(int);
    void timeChanged(int);

private:
    int id;
    int verdict;
    int memory;
    int time;
};

#endif // TESTSUBMIT_H
