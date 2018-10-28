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

Problem &Problem::operator=(const Problem &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Problem Problem::create(const QString &title, const QString &description, int timeLimit, int memoryLimit, int triesLeft, int points, int penaltyTry, int penaltyTime, int contestId)
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

int Problem::count()
{
    TSqlORMapper<ProblemObject> mapper;
    return mapper.findCount();
}

QList<Problem> Problem::getAll()
{
    return tfGetModelListByCriteria<Problem, ProblemObject>(TCriteria());
}

QJsonArray Problem::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ProblemObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ProblemObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Problem(i.next()).toVariantMap())));
        }
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

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Problem)
