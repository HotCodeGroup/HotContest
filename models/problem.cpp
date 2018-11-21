#include <TreeFrogModel>
#include "problem.h"
#include "problemobject.h"

Problem::Problem()
    : TAbstractModel(), d(new ProblemObject())
{
    d->problem_id = 0;
    d->time_limit = 0;
    d->memory_limit = 0;
    d->tries_left = 0;
    d->points = 0;
    d->penalty_try = 0;
    d->penalty_time = 0;
    d->contest_id = 0;
    d->lock_revision = 0;
    d->in_contest_id = 0;
}

Problem::Problem(const Problem &other)
    : TAbstractModel(), d(new ProblemObject(*other.d))
{ }

Problem::Problem(const ProblemObject &object)
    : TAbstractModel(), d(new ProblemObject(object))
{ }

Problem::~Problem()
{
    // If the reference count becomes 0,
    // the shared data object 'ProblemObject' is deleted.
}

int Problem::problemId() const
{
    return d->problem_id;
}

QString Problem::title() const
{
    return d->title;
}

void Problem::setTitle(const QString &title)
{
    d->title = title;
}

QString Problem::description() const
{
    return d->description;
}

void Problem::setDescription(const QString &description)
{
    d->description = description;
}

int Problem::timeLimit() const
{
    return d->time_limit;
}

void Problem::setTimeLimit(int timeLimit)
{
    d->time_limit = timeLimit;
}

int Problem::memoryLimit() const
{
    return d->memory_limit;
}

void Problem::setMemoryLimit(int memoryLimit)
{
    d->memory_limit = memoryLimit;
}

int Problem::triesLeft() const
{
    return d->tries_left;
}

void Problem::setTriesLeft(int triesLeft)
{
    d->tries_left = triesLeft;
}

int Problem::points() const
{
    return d->points;
}

void Problem::setPoints(int points)
{
    d->points = points;
}

int Problem::penaltyTry() const
{
    return d->penalty_try;
}

void Problem::setPenaltyTry(int penaltyTry)
{
    d->penalty_try = penaltyTry;
}

int Problem::penaltyTime() const
{
    return d->penalty_time;
}

void Problem::setPenaltyTime(int penaltyTime)
{
    d->penalty_time = penaltyTime;
}

int Problem::contestId() const
{
    return d->contest_id;
}

void Problem::setContestId(int contestId)
{
    d->contest_id = contestId;
}

int Problem::lockRevision() const
{
    return d->lock_revision;
}

int Problem::inContestId() const
{
    return d->in_contest_id;
}

void Problem::setInContestId(int inContestId)
{
    d->in_contest_id = inContestId;
}

Problem &Problem::operator=(const Problem &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Problem Problem::create(const QString &title, const QString &description, int timeLimit, int memoryLimit, int triesLeft, int points, int penaltyTry, int penaltyTime, int contestId, int inContestId)
{
    ProblemObject obj;
    obj.title = title;
    obj.description = description;
    obj.time_limit = timeLimit;
    obj.memory_limit = memoryLimit;
    obj.tries_left = triesLeft;
    obj.points = points;
    obj.penalty_try = penaltyTry;
    obj.penalty_time = penaltyTime;
    obj.contest_id = contestId;
    obj.in_contest_id = inContestId;
    if (!obj.create()) {
        return Problem();
    }
    return Problem(obj);
}

Problem Problem::create(const QVariantMap &values)
{
    Problem model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Problem Problem::get(int problemId)
{
    TSqlORMapper<ProblemObject> mapper;
    return Problem(mapper.findByPrimaryKey(problemId));
}

Problem Problem::get(int problemId, int lockRevision)
{
    TSqlORMapper<ProblemObject> mapper;
    TCriteria cri;
    cri.add(ProblemObject::ProblemId, problemId);
    cri.add(ProblemObject::LockRevision, lockRevision);
    return Problem(mapper.findFirst(cri));
}

Problem Problem::getWithContest(int contestId, int problemId)
{
    TSqlORMapper<ProblemObject> mapper;
    TCriteria cri;
    cri.add(ProblemObject::ContestId, contestId);
    cri.add(ProblemObject::InContestId, problemId);
    return Problem(mapper.findFirst(cri));
}

Problem Problem::getWithContest(int contestId, int problemId, int lockRevision)
{
    TSqlORMapper<ProblemObject> mapper;
    TCriteria cri;
    cri.add(ProblemObject::ContestId, contestId);
    cri.add(ProblemObject::InContestId, problemId);
    cri.add(ProblemObject::LockRevision, lockRevision);
    return Problem(mapper.findFirst(cri));
}

int Problem::count()
{
    TSqlORMapper<ProblemObject> mapper;
    return mapper.findCount();
}

QList<Problem> Problem::getAll(int contestID)
{
    if (contestID) {
        TCriteria cri;
        cri.add(ProblemObject::ContestId, contestID);
        return tfGetModelListByCriteria<Problem, ProblemObject>(cri, ProblemObject::InContestId,
                Qt::SortOrder::AscendingOrder);
    }

    return tfGetModelListByCriteria<Problem, ProblemObject>();
}

QJsonArray Problem::getAllJson(int contestID)
{
    QJsonArray array;
    TSqlORMapper<ProblemObject> mapper;

    TCriteria cri;
    if (contestID) {
        cri.add(ProblemObject::ContestId, contestID);
        mapper.sort(ProblemObject::InContestId, Qt::SortOrder::AscendingOrder);
    }

    if (mapper.find(cri) > 0) {
        for (TSqlORMapperIterator<ProblemObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Problem(i.next()).toVariantMap())));
        }
    }
    return array;
}

QJsonArray Problem::getShortAllJson(int userID, int contestID) {
    if (!contestID || !userID) {
        return QJsonArray();
    }

    TSqlQuery query;
    query.prepare("WITH done_problems AS (select so.problem_id\n"
                  "                       from solution so\n"
                  "                              join submit su on so.solution_id = su.solution_id\n"
                  "                       where so.user_id = ?\n"
                  "                         AND su.resp_code = 0)\n"
                  "SELECT p.title, p.points, exists(select 1 FROM done_problems dp WHERE dp.problem_id = p.problem_id) AS \"is_done\"\n"
                  "FROM problem p\n"
                  "WHERE contest_id = ?\n"
                  "ORDER BY in_contest_id ASC;");
    query.addBind(userID).addBind(contestID);
    query.exec();

    QJsonArray array;
    QJsonObject info;
    while (query.next()) {
        info["title"] = query.value(0).toString();
        info["points"] = query.value(1).toInt();
        info["isDone"] = query.value(2).toBool();

        array.append(info);
    }

    return array;
}


TModelObject *Problem::modelData()
{
    return d.data();
}

const TModelObject *Problem::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Problem &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Problem &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

QVariantMap Problem::toVariantMapLight() const {
    auto superMap = TAbstractModel::toVariantMap();
    superMap.remove("contestId");
    superMap.remove("lockRevision");

    return superMap;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Problem)
