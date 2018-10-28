#include <TreeFrogModel>
#include "contest.h"
#include "contestobject.h"

Contest::Contest()
    : TAbstractModel(), d(new ContestObject())
{
    d->contest_id = 0;
    d->lock_revision = 0;
}

Contest::Contest(const Contest &other)
    : TAbstractModel(), d(new ContestObject(*other.d))
{ }

Contest::Contest(const ContestObject &object)
    : TAbstractModel(), d(new ContestObject(object))
{ }

Contest::~Contest()
{
    // If the reference count becomes 0,
    // the shared data object 'ContestObject' is deleted.
}

int Contest::contestId() const
{
    return d->contest_id;
}

QString Contest::title() const
{
    return d->title;
}

void Contest::setTitle(const QString &title)
{
    d->title = title;
}

QString Contest::description() const
{
    return d->description;
}

void Contest::setDescription(const QString &description)
{
    d->description = description;
}

QDateTime Contest::startTime() const
{
    return d->start_time;
}

void Contest::setStartTime(const QDateTime &startTime)
{
    d->start_time = startTime;
}

QDateTime Contest::finishTime() const
{
    return d->finish_time;
}

void Contest::setFinishTime(const QDateTime &finishTime)
{
    d->finish_time = finishTime;
}

bool Contest::isPrivate() const
{
    return d->is_private;
}

void Contest::setIsPrivate(const bool &isPrivate)
{
    d->is_private = isPrivate;
}

bool Contest::isActive() const
{
    return d->is_active;
}

void Contest::setIsActive(const bool &isActive)
{
    d->is_active = isActive;
}

int Contest::lockRevision() const
{
    return d->lock_revision;
}

Contest &Contest::operator=(const Contest &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Contest Contest::create(const QString &title, const QString &description, const QDateTime &startTime, const QDateTime &finishTime, const bool &isPrivate, const bool &isActive)
{
    ContestObject obj;
    obj.title = title;
    obj.description = description;
    obj.start_time = startTime;
    obj.finish_time = finishTime;
    obj.is_private = isPrivate;
    obj.is_active = isActive;
    if (!obj.create()) {
        return Contest();
    }
    return Contest(obj);
}

Contest Contest::create(const QVariantMap &values)
{
    Contest model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Contest Contest::get(int contestId)
{
    TSqlORMapper<ContestObject> mapper;
    return Contest(mapper.findByPrimaryKey(contestId));
}

Contest Contest::get(int contestId, int lockRevision)
{
    TSqlORMapper<ContestObject> mapper;
    TCriteria cri;
    cri.add(ContestObject::ContestId, contestId);
    cri.add(ContestObject::LockRevision, lockRevision);
    return Contest(mapper.findFirst(cri));
}

int Contest::count()
{
    TSqlORMapper<ContestObject> mapper;
    return mapper.findCount();
}

QList<Contest> Contest::getAll()
{
    return tfGetModelListByCriteria<Contest, ContestObject>(TCriteria());
}

QJsonArray Contest::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ContestObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ContestObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Contest(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Contest::modelData()
{
    return d.data();
}

const TModelObject *Contest::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Contest &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Contest &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Contest)
