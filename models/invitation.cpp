#include <TreeFrogModel>
#include "invitation.h"
#include "invitationobject.h"

Invitation::Invitation()
    : TAbstractModel(), d(new InvitationObject())
{
    d->invitation_id = 0;
    d->state = 0;
    d->sender_id = 0;
    d->addresse_id = 0;
    d->contest_id = 0;
    d->lock_revision = 0;
}

Invitation::Invitation(const Invitation &other)
    : TAbstractModel(), d(new InvitationObject(*other.d))
{ }

Invitation::Invitation(const InvitationObject &object)
    : TAbstractModel(), d(new InvitationObject(object))
{ }

Invitation::~Invitation()
{
    // If the reference count becomes 0,
    // the shared data object 'InvitationObject' is deleted.
}

int Invitation::invitationId() const
{
    return d->invitation_id;
}

int Invitation::state() const
{
    return d->state;
}

void Invitation::setState(int state)
{
    d->state = state;
}

int Invitation::senderId() const
{
    return d->sender_id;
}

void Invitation::setSenderId(int senderId)
{
    d->sender_id = senderId;
}

int Invitation::addresseId() const
{
    return d->addresse_id;
}

void Invitation::setAddresseId(int addresseId)
{
    d->addresse_id = addresseId;
}

int Invitation::contestId() const
{
    return d->contest_id;
}

void Invitation::setContestId(int contestId)
{
    d->contest_id = contestId;
}

int Invitation::lockRevision() const
{
    return d->lock_revision;
}

Invitation &Invitation::operator=(const Invitation &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Invitation Invitation::create(int state, int senderId, int addresseId, int contestId)
{
    InvitationObject obj;
    obj.state = state;
    obj.sender_id = senderId;
    obj.addresse_id = addresseId;
    obj.contest_id = contestId;
    if (!obj.create()) {
        return Invitation();
    }
    return Invitation(obj);
}

Invitation Invitation::create(const QVariantMap &values)
{
    Invitation model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Invitation Invitation::get(int invitationId)
{
    TSqlORMapper<InvitationObject> mapper;
    return Invitation(mapper.findByPrimaryKey(invitationId));
}

Invitation Invitation::get(int invitationId, int lockRevision)
{
    TSqlORMapper<InvitationObject> mapper;
    TCriteria cri;
    cri.add(InvitationObject::InvitationId, invitationId);
    cri.add(InvitationObject::LockRevision, lockRevision);
    return Invitation(mapper.findFirst(cri));
}

int Invitation::count()
{
    TSqlORMapper<InvitationObject> mapper;
    return mapper.findCount();
}

QList<Invitation> Invitation::getAll()
{
    return tfGetModelListByCriteria<Invitation, InvitationObject>(TCriteria());
}

QJsonArray Invitation::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<InvitationObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<InvitationObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Invitation(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Invitation::modelData()
{
    return d.data();
}

const TModelObject *Invitation::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Invitation &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Invitation &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Invitation)
