#ifndef INVITATIONOBJECT_H
#define INVITATIONOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT InvitationObject : public TSqlObject, public QSharedData
{
public:
    int invitation_id {0};
    int state {0};
    int sender_id {0};
    int addresse_id {0};
    int contest_id {0};
    int lock_revision {0};

    enum PropertyIndex {
        InvitationId = 0,
        State,
        SenderId,
        AddresseId,
        ContestId,
        LockRevision,
    };

    int primaryKeyIndex() const override { return InvitationId; }
    int autoValueIndex() const override { return InvitationId; }
    QString tableName() const override { return QLatin1String("invitation"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int invitation_id READ getinvitation_id WRITE setinvitation_id)
    T_DEFINE_PROPERTY(int, invitation_id)
    Q_PROPERTY(int state READ getstate WRITE setstate)
    T_DEFINE_PROPERTY(int, state)
    Q_PROPERTY(int sender_id READ getsender_id WRITE setsender_id)
    T_DEFINE_PROPERTY(int, sender_id)
    Q_PROPERTY(int addresse_id READ getaddresse_id WRITE setaddresse_id)
    T_DEFINE_PROPERTY(int, addresse_id)
    Q_PROPERTY(int contest_id READ getcontest_id WRITE setcontest_id)
    T_DEFINE_PROPERTY(int, contest_id)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // INVITATIONOBJECT_H
