#ifndef TESTSUBMITOBJECT_H
#define TESTSUBMITOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TestSubmitObject : public TSqlObject, public QSharedData
{
public:
    int test_submit_id {0};
    QString verdict;
    int time {0};
    int memory {0};
    int test_id {0};
    int submit_id {0};
    int lock_revision {0};

    enum PropertyIndex {
        TestSubmitId = 0,
        Verdict,
        Time,
        Memory,
        TestId,
        SubmitId,
        LockRevision,
    };

    int primaryKeyIndex() const override { return TestSubmitId; }
    int autoValueIndex() const override { return TestSubmitId; }
    QString tableName() const override { return QLatin1String("test_submit"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int test_submit_id READ gettest_submit_id WRITE settest_submit_id)
    T_DEFINE_PROPERTY(int, test_submit_id)
    Q_PROPERTY(QString verdict READ getverdict WRITE setverdict)
    T_DEFINE_PROPERTY(QString, verdict)
    Q_PROPERTY(int time READ gettime WRITE settime)
    T_DEFINE_PROPERTY(int, time)
    Q_PROPERTY(int memory READ getmemory WRITE setmemory)
    T_DEFINE_PROPERTY(int, memory)
    Q_PROPERTY(int test_id READ gettest_id WRITE settest_id)
    T_DEFINE_PROPERTY(int, test_id)
    Q_PROPERTY(int submit_id READ getsubmit_id WRITE setsubmit_id)
    T_DEFINE_PROPERTY(int, submit_id)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // TESTSUBMITOBJECT_H
