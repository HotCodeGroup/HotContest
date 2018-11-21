#include <TreeFrogModel>
#include "contest.h"
#include "contestobject.h"
#include "profile.h"
#include "profileobject.h"

Contest::Contest()
    : TAbstractModel(), d(new ContestObject())
{
    d->contest_id = 0;
    d->participants_count = 0;
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

int Contest::participantsCount() const
{
    return d->participants_count;
}

void Contest::setParticipantsCount(int participantsCount)
{
    d->participants_count = participantsCount;
}

int Contest::lockRevision() const
{
    return d->lock_revision;
}

QStringList Contest::participants(int limit, int offset) const {
    TSqlQuery query;
    query.prepare("SELECT pr.nickname FROM profile pr JOIN participant pa on pr.user_id = pa.user_id WHERE pa.contest_id = ? ORDER BY pr.user_id LIMIT ? OFFSET ?;");
    query.addBind(contestId()).addBind(limit).addBind(offset);
    query.exec();

    QStringList array;
    while (query.next()) {
        array << query.value(0).toString();
    }

    return array;
}
//
//QList<QVariantMap> Contest::scores(int limit, int offset) const {
//    TSqlQuery query;
//    query.prepare("with big_table as (select prof.user_id as u_id, prof.nickname, co.contest_id as c_id, pr.problem_id as p_id, pr.points,\n"
//                  "                          pr.penalty_try, pr.penalty_time, submit_time, resp_code\n"
//                  "                   from contest co\n"
//                  "                          join problem pr on co.contest_id = pr.contest_id and co.contest_id = 1\n"
//                  "                          join solution so on so.problem_id = pr.problem_id\n"
//                  "                          join profile prof on prof.user_id = so.user_id\n"
//                  "                          join submit su on su.solution_id = so.solution_id),\n"
//                  "     ok_date as (select u_id, c_id, p_id, count(*) comp, min(submit_time) fst\n"
//                  "                 from big_table\n"
//                  "                 where resp_code = 0\n"
//                  "                 group by u_id, c_id, p_id),\n"
//                  "     err_list as (select o.u_id, o.c_id, o.p_id, count(*) err\n"
//                  "                  from big_table b\n"
//                  "                         join ok_date o on b.u_id = o.u_id and b.p_id = o.p_id and b.c_id = o.c_id\n"
//                  "                  WHERE resp_code != 0\n"
//                  "                    and b.submit_time < o.fst\n"
//                  "                  group by o.u_id, o.c_id, o.p_id)\n"
//                  "select distinct b.u_id, b.p_id, b.nickname, b.points, b.penalty_try, b.penalty_time, o.fst, e.err\n"
//                  "from big_table b\n"
//                  "       left join err_list e on b.u_id = e.u_id and b.p_id = e.p_id and b.c_id = e.c_id\n"
//                  "       join ok_date o on b.u_id = o.u_id and b.p_id = o.p_id and b.c_id = o.c_id\n"
//                  "ORDER BY b.u_id, b.p_id;");
//    query.addBind(contestId());
//    query.exec();
//
//    return array;
//}

Contest &Contest::operator=(const Contest &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Contest Contest::create(const QString &title, const QString &description, const QDateTime &startTime, const QDateTime &finishTime, const bool &isPrivate, const bool &isActive, int participantsCount)
{
    ContestObject obj;
    obj.title = title;
    obj.description = description;
    obj.start_time = startTime;
    obj.finish_time = finishTime;
    obj.is_private = isPrivate;
    obj.is_active = isActive;
    obj.participants_count = participantsCount;
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

int Contest::countPublic() {
    TSqlORMapper<ContestObject> mapper;
    TCriteria cri;
    cri.add(ContestObject::IsPrivate, false);
    return mapper.findCount(cri);
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

QJsonArray Contest::getJsonList(int limit, int offset)
{
    QJsonArray array;
    TSqlORMapper<ContestObject> mapper;

    TCriteria cri;
    cri.add(ContestObject::IsPrivate, false);

    mapper.setLimit(limit);
    mapper.setOffset(offset);

    mapper.orderBy(ContestObject::StartTime, Tf::SortOrder::DescendingOrder);

    if (mapper.find(cri) > 0) {
        for (TSqlORMapperIterator<ContestObject> i(mapper); i.hasNext(); ) {
            auto contestVariantMap = Contest(i.next()).toVariantMap();
            contestVariantMap.remove("description");
            contestVariantMap.remove("isPrivate");
            contestVariantMap.remove("lockRevision");

            array.append(QJsonValue(QJsonObject::fromVariantMap(contestVariantMap)));
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

QVariantMap Contest::toVariantMapLight() const {
    auto superMap = TAbstractModel::toVariantMap();
    superMap.remove("isPrivate");
    superMap.remove("lockRevision");

    return superMap;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Contest)
