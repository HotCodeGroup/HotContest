#ifndef PROBLEMOBJECT_H
#define PROBLEMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ProblemObject : public TSqlObject, public QSharedData
{
public:
    int problem_id {0};
    QString title;
    QString description;
    int time_limit {0};
    int memory_limit {0};
    int tries_left {0};
    int points {0};
    int penalty_try {0};
    int penalty_time {0};
    int contest_id {0};
    int lock_revision {0};

    enum PropertyIndex {
        ProblemId = 0,
        Title,
        Description,
        TimeLimit,
        MemoryLimit,
        TriesLeft,
        Points,
        PenaltyTry,
        PenaltyTime,
        ContestId,
        LockRevision,
    };

    int primaryKeyIndex() const override { return ProblemId; }
    int autoValueIndex() const override { return ProblemId; }
    QString tableName() const override { return QLatin1String("problem"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int problem_id READ getproblem_id WRITE setproblem_id)
    T_DEFINE_PROPERTY(int, problem_id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString description READ getdescription WRITE setdescription)
    T_DEFINE_PROPERTY(QString, description)
    Q_PROPERTY(int time_limit READ gettime_limit WRITE settime_limit)
    T_DEFINE_PROPERTY(int, time_limit)
    Q_PROPERTY(int memory_limit READ getmemory_limit WRITE setmemory_limit)
    T_DEFINE_PROPERTY(int, memory_limit)
    Q_PROPERTY(int tries_left READ gettries_left WRITE settries_left)
    T_DEFINE_PROPERTY(int, tries_left)
    Q_PROPERTY(int points READ getpoints WRITE setpoints)
    T_DEFINE_PROPERTY(int, points)
    Q_PROPERTY(int penalty_try READ getpenalty_try WRITE setpenalty_try)
    T_DEFINE_PROPERTY(int, penalty_try)
    Q_PROPERTY(int penalty_time READ getpenalty_time WRITE setpenalty_time)
    T_DEFINE_PROPERTY(int, penalty_time)
    Q_PROPERTY(int contest_id READ getcontest_id WRITE setcontest_id)
    T_DEFINE_PROPERTY(int, contest_id)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // PROBLEMOBJECT_H
