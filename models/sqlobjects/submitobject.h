#ifndef SUBMITOBJECT_H
#define SUBMITOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SubmitObject : public TSqlObject, public QSharedData
{
public:
    int submit_id {0};
    QString resp_code;
    int error_test {0};
    int time {0};
    int memory {0};
    int solution_id {0};
    int lock_revision {0};

    enum PropertyIndex {
        SubmitId = 0,
        RespCode,
        ErrorTest,
        Time,
        Memory,
        SolutionId,
        LockRevision,
    };

    int primaryKeyIndex() const override { return SubmitId; }
    int autoValueIndex() const override { return SubmitId; }
    QString tableName() const override { return QLatin1String("submit"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int submit_id READ getsubmit_id WRITE setsubmit_id)
    T_DEFINE_PROPERTY(int, submit_id)
    Q_PROPERTY(QString resp_code READ getresp_code WRITE setresp_code)
    T_DEFINE_PROPERTY(QString, resp_code)
    Q_PROPERTY(int error_test READ geterror_test WRITE seterror_test)
    T_DEFINE_PROPERTY(int, error_test)
    Q_PROPERTY(int time READ gettime WRITE settime)
    T_DEFINE_PROPERTY(int, time)
    Q_PROPERTY(int memory READ getmemory WRITE setmemory)
    T_DEFINE_PROPERTY(int, memory)
    Q_PROPERTY(int solution_id READ getsolution_id WRITE setsolution_id)
    T_DEFINE_PROPERTY(int, solution_id)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // SUBMITOBJECT_H
