#ifndef CONTESTOBJECT_H
#define CONTESTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ContestObject : public TSqlObject, public QSharedData
{
public:
    int contest_id {0};
    QString title;
    QString description;
    QDateTime start_time;
    QDateTime finish_time;
    bool is_private;
    bool is_active;
    int lock_revision {0};

    enum PropertyIndex {
        ContestId = 0,
        Title,
        Description,
        StartTime,
        FinishTime,
        IsPrivate,
        IsActive,
        LockRevision,
    };

    int primaryKeyIndex() const override { return ContestId; }
    int autoValueIndex() const override { return ContestId; }
    QString tableName() const override { return QLatin1String("contest"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int contest_id READ getcontest_id WRITE setcontest_id)
    T_DEFINE_PROPERTY(int, contest_id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString description READ getdescription WRITE setdescription)
    T_DEFINE_PROPERTY(QString, description)
    Q_PROPERTY(QDateTime start_time READ getstart_time WRITE setstart_time)
    T_DEFINE_PROPERTY(QDateTime, start_time)
    Q_PROPERTY(QDateTime finish_time READ getfinish_time WRITE setfinish_time)
    T_DEFINE_PROPERTY(QDateTime, finish_time)
    Q_PROPERTY(bool is_private READ getis_private WRITE setis_private)
    T_DEFINE_PROPERTY(bool, is_private)
    Q_PROPERTY(bool is_active READ getis_active WRITE setis_active)
    T_DEFINE_PROPERTY(bool, is_active)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // CONTESTOBJECT_H
