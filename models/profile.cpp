#include <TreeFrogModel>
#include "profile.h"
#include "profileobject.h"

Profile::Profile()
    : TAbstractModel(), d(new ProfileObject())
{
    d->user_id = 0;
    d->lock_revision = 0;
}

Profile::Profile(const Profile &other)
    : TAbstractModel(), d(new ProfileObject(*other.d))
{ }

Profile::Profile(const ProfileObject &object)
    : TAbstractModel(), d(new ProfileObject(object))
{ }

Profile::~Profile()
{
    // If the reference count becomes 0,
    // the shared data object 'ProfileObject' is deleted.
}

int Profile::userId() const
{
    return d->user_id;
}

QString Profile::firstName() const
{
    return d->first_name;
}

void Profile::setFirstName(const QString &firstName)
{
    d->first_name = firstName;
}

QString Profile::lastName() const
{
    return d->last_name;
}

void Profile::setLastName(const QString &lastName)
{
    d->last_name = lastName;
}

QString Profile::nickname() const
{
    return d->nickname;
}

void Profile::setNickname(const QString &nickname)
{
    d->nickname = nickname;
}

QString Profile::email() const
{
    return d->email;
}

void Profile::setEmail(const QString &email)
{
    d->email = email;
}

QString Profile::password() const
{
    return d->password;
}

void Profile::setPassword(const QString &password)
{
    d->password = password;
}

QDateTime Profile::dateJoined() const
{
    return d->date_joined;
}

void Profile::setDateJoined(const QDateTime &dateJoined)
{
    d->date_joined = dateJoined;
}

bool Profile::isActive() const
{
    return d->is_active;
}

void Profile::setIsActive(const bool &isActive)
{
    d->is_active = isActive;
}

int Profile::lockRevision() const
{
    return d->lock_revision;
}

Profile &Profile::operator=(const Profile &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Profile Profile::create(const QString &firstName, const QString &lastName, const QString &nickname, const QString &email, const QString &password, const QDateTime &dateJoined, const bool &isActive)
{
    ProfileObject obj;
    obj.first_name = firstName;
    obj.last_name = lastName;
    obj.nickname = nickname;
    obj.email = email;
    obj.password = password;
    obj.date_joined = dateJoined;
    obj.is_active = isActive;
    if (!obj.create()) {
        return Profile();
    }
    return Profile(obj);
}

Profile Profile::create(const QVariantMap &values)
{
    Profile model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Profile Profile::get(int userId)
{
    TSqlORMapper<ProfileObject> mapper;
    return Profile(mapper.findByPrimaryKey(userId));
}

Profile Profile::get(int userId, int lockRevision)
{
    TSqlORMapper<ProfileObject> mapper;
    TCriteria cri;
    cri.add(ProfileObject::UserId, userId);
    cri.add(ProfileObject::LockRevision, lockRevision);
    return Profile(mapper.findFirst(cri));
}

int Profile::count()
{
    TSqlORMapper<ProfileObject> mapper;
    return mapper.findCount();
}

QList<Profile> Profile::getAll()
{
    return tfGetModelListByCriteria<Profile, ProfileObject>(TCriteria());
}

QJsonArray Profile::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ProfileObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ProfileObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Profile(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Profile::modelData()
{
    return d.data();
}

const TModelObject *Profile::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Profile &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Profile &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Profile)
