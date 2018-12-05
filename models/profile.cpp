#include <TreeFrogModel>
#include "profile.h"
#include "profileobject.h"

Profile::Profile()
    : TAbstractUser(), TAbstractModel(), d(new ProfileObject())
{
    d->user_id = 0;
    d->lock_revision = 0;
}

Profile::Profile(const Profile &other)
    : TAbstractUser(), TAbstractModel(), d(new ProfileObject(*other.d))
{ }

Profile::Profile(const ProfileObject &object)
    : TAbstractUser(), TAbstractModel(), d(new ProfileObject(object))
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

QString Profile::username() const
{
    return d->username;
}

void Profile::setUsername(const QString &username)
{
    d->username = username;
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

QDateTime Profile::createdAt() const
{
    return d->created_at;
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

Profile Profile::authenticate(const QString &username, const QString &password)
{
    if (username.isEmpty() || password.isEmpty())
        return Profile();

    TSqlORMapper<ProfileObject> mapper;
    ProfileObject obj = mapper.findFirst(TCriteria(ProfileObject::Username, username));
    if (obj.isNull()) {
        obj.clear();
    } else {
        auto hash = QCryptographicHash::hash(password.toUtf8(),
                                             QCryptographicHash::Sha256).toHex();
        if (obj.password != hash) {
            obj.clear();
        }
    }

    return Profile(obj);
}

Profile Profile::create(const QString &firstName, const QString &lastName, const QString &username, const QString &email, const QString &password, const bool &isActive)
{
    ProfileObject obj;
    obj.first_name = firstName;
    obj.last_name = lastName;
    obj.username = username;
    obj.email = email;
    obj.password = password;
    obj.is_active = isActive;
    if (!obj.create()) {
        return Profile();
    }
    return Profile(obj);
}

Profile Profile::create(QVariantMap &values)
{
    Profile model;
    values["password"] = QCryptographicHash::hash(values["password"].toString().toUtf8(), QCryptographicHash::Sha256).toHex();
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

Profile Profile::getByUsername(const QString &usrname)
{
    TSqlORMapper<ProfileObject> mapper;
    TCriteria cri;
    cri.add(ProfileObject::Username, usrname);
    return Profile(mapper.findFirst(cri));
}

Profile Profile::getByEmail(const QString &email)
{
    TSqlORMapper<ProfileObject> mapper;
    TCriteria cri;
    cri.add(ProfileObject::Email, email);
    return Profile(mapper.findFirst(cri));
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
    return tfGetModelListByCriteria<Profile, ProfileObject>();
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

void Profile::updateProperties(const QVariantMap &value) {
    if (value.find("first_name") != value.end()) setFirstName(value["first_name"].toString());
    if (value.find("second_name") != value.end()) setLastName(value["second_name"].toString());
    if (value.find("email") != value.end()) setEmail(value["email"].toString());
    if (value.find("password") != value.end()) {
        setPassword(QCryptographicHash::hash(value["password"].toString().toUtf8(), QCryptographicHash::Sha256).toHex());
    }
}

QVariantMap Profile::toVariantMapLight() const {
    auto superMap = TAbstractModel::toVariantMap();
    superMap.remove("password");
    superMap.remove("lockRevision");

    return superMap;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Profile)