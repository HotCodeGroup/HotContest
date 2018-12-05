#include <TreeFrogModel>
#include "solution.h"
#include "solutionobject.h"
#include "profile.h"


Solution::Solution()
    : TAbstractModel(), d(new SolutionObject())
{
    d->solution_id = 0;
    d->user_id = 0;
    d->lock_revision = 0;
    d->problem_id = 0;
}

Solution::Solution(const Solution &other)
    : TAbstractModel(), d(new SolutionObject(*other.d))
{ }

Solution::Solution(const SolutionObject &object)
    : TAbstractModel(), d(new SolutionObject(object))
{ }

Solution::~Solution()
{
    // If the reference count becomes 0,
    // the shared data object 'SolutionObject' is deleted.
}

int Solution::solutionId() const
{
    return d->solution_id;
}

QString Solution::srcFile() const
{
    return d->src_file;
}

void Solution::setSrcFile(const QString &srcFile)
{
    d->src_file = srcFile;
}

QDateTime Solution::submitTime() const
{
    return d->submit_time;
}

void Solution::setSubmitTime(const QDateTime &submitTime)
{
    d->submit_time = submitTime;
}

int Solution::userId() const
{
    return d->user_id;
}

void Solution::setUserId(int userId)
{
    d->user_id = userId;
}

int Solution::lockRevision() const
{
    return d->lock_revision;
}

int Solution::problemId() const
{
    return d->problem_id;
}

void Solution::setProblemId(int problemId)
{
    d->problem_id = problemId;
}

Solution &Solution::operator=(const Solution &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Solution Solution::create(const QString &srcFile, const QDateTime &submitTime, int userId, int problemId)
{
    SolutionObject obj;
    obj.src_file = srcFile;
    obj.submit_time = submitTime;
    obj.user_id = userId;
    obj.problem_id = problemId;
    if (!obj.create()) {
        return Solution();
    }
    return Solution(obj);
}

Solution Solution::create(const QVariantMap &values)
{
    Solution model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Solution Solution::get(int solutionId)
{
    TSqlORMapper<SolutionObject> mapper;
    return Solution(mapper.findByPrimaryKey(solutionId));
}

Solution Solution::get(int solutionId, int lockRevision)
{
    TSqlORMapper<SolutionObject> mapper;
    TCriteria cri;
    cri.add(SolutionObject::SolutionId, solutionId);
    cri.add(SolutionObject::LockRevision, lockRevision);
    return Solution(mapper.findFirst(cri));
}

int Solution::count()
{
    TSqlORMapper<SolutionObject> mapper;
    return mapper.findCount();
}

QList<Solution> Solution::getAll()
{
    return tfGetModelListByCriteria<Solution, SolutionObject>(TCriteria());
}

QJsonArray Solution::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<SolutionObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<SolutionObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Solution(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Solution::modelData()
{
    return d.data();
}

const TModelObject *Solution::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Solution &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Solution &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Solution)
