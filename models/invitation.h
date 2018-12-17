#ifndef INVITATION_H
#define INVITATION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class InvitationObject;
class QJsonArray;


class T_MODEL_EXPORT Invitation : public TAbstractModel
{
public:
    Invitation();
    Invitation(const Invitation &other);
    Invitation(const InvitationObject &object);
    ~Invitation();

    int invitationId() const;
    int state() const;
    void setState(int state);
    int senderId() const;
    void setSenderId(int senderId);
    int addresseId() const;
    void setAddresseId(int addresseId);
    int contestId() const;
    void setContestId(int contestId);
    int lockRevision() const;
    Invitation &operator=(const Invitation &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Invitation create(int state, int senderId, int addresseId, int contestId);
    static Invitation create(const QVariantMap &values);
    static Invitation get(int invitationId);
    static Invitation get(int invitationId, int lockRevision);
    static int count();
    static QList<Invitation> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<InvitationObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Invitation &model);
    friend QDataStream &operator>>(QDataStream &ds, Invitation &model);
};

Q_DECLARE_METATYPE(Invitation)
Q_DECLARE_METATYPE(QList<Invitation>)

#endif // INVITATION_H
