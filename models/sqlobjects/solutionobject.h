#ifndef SOLUTIONOBJECT_H
#define SOLUTIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT SolutionObject : public TSqlObject, public QSharedData
{
public:
    int solution_id {0};
    QString src_file;
    QDateTime submit_time;
    int user_id {0};
    int lock_revision {0};
    int problem_id {0};

    enum PropertyIndex {
        SolutionId = 0,
        SrcFile,
        SubmitTime,
        UserId,
        LockRevision,
        ProblemId,
    };

    int primaryKeyIndex() const override { return SolutionId; }
    int autoValueIndex() const override { return SolutionId; }
    QString tableName() const override { return QLatin1String("solution"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int solution_id READ getsolution_id WRITE setsolution_id)
    T_DEFINE_PROPERTY(int, solution_id)
    Q_PROPERTY(QString src_file READ getsrc_file WRITE setsrc_file)
    T_DEFINE_PROPERTY(QString, src_file)
    Q_PROPERTY(QDateTime submit_time READ getsubmit_time WRITE setsubmit_time)
    T_DEFINE_PROPERTY(QDateTime, submit_time)
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
    Q_PROPERTY(int problem_id READ getproblem_id WRITE setproblem_id)
    T_DEFINE_PROPERTY(int, problem_id)
};

#endif // SOLUTIONOBJECT_H
