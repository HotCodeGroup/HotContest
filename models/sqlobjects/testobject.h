#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT TestObject : public TSqlObject, public QSharedData
{
public:
    int test_id {0};
    QString input;
    QString output;
    int problem_id {0};
    int lock_revision {0};

    enum PropertyIndex {
        TestId = 0,
        Input,
        Output,
        ProblemId,
        LockRevision,
    };

    int primaryKeyIndex() const override { return TestId; }
    int autoValueIndex() const override { return TestId; }
    QString tableName() const override { return QLatin1String("test"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int test_id READ gettest_id WRITE settest_id)
    T_DEFINE_PROPERTY(int, test_id)
    Q_PROPERTY(QString input READ getinput WRITE setinput)
    T_DEFINE_PROPERTY(QString, input)
    Q_PROPERTY(QString output READ getoutput WRITE setoutput)
    T_DEFINE_PROPERTY(QString, output)
    Q_PROPERTY(int problem_id READ getproblem_id WRITE setproblem_id)
    T_DEFINE_PROPERTY(int, problem_id)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // TESTOBJECT_H
