#ifndef MESSAGEOBJECT_H
#define MESSAGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MessageObject : public TSqlObject, public QSharedData
{
public:
    int message_id {0};
    QString text;
    QDateTime time_stamp;
    int author_id {0};
    int contest_id {0};
    int lock_revision {0};

    enum PropertyIndex {
        MessageId = 0,
        Text,
        TimeStamp,
        AuthorId,
        ContestId,
        LockRevision,
    };

    int primaryKeyIndex() const override { return MessageId; }
    int autoValueIndex() const override { return MessageId; }
    QString tableName() const override { return QLatin1String("message"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int message_id READ getmessage_id WRITE setmessage_id)
    T_DEFINE_PROPERTY(int, message_id)
    Q_PROPERTY(QString text READ gettext WRITE settext)
    T_DEFINE_PROPERTY(QString, text)
    Q_PROPERTY(QDateTime time_stamp READ gettime_stamp WRITE settime_stamp)
    T_DEFINE_PROPERTY(QDateTime, time_stamp)
    Q_PROPERTY(int author_id READ getauthor_id WRITE setauthor_id)
    T_DEFINE_PROPERTY(int, author_id)
    Q_PROPERTY(int contest_id READ getcontest_id WRITE setcontest_id)
    T_DEFINE_PROPERTY(int, contest_id)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // MESSAGEOBJECT_H
