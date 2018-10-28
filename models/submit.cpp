#include <TreeFrogModel>
#include "submit.h"
#include "submitobject.h"

Submit::Submit()
    : TAbstractModel(), d(new SubmitObject())
{
    d->submit_id = 0;
    d->error_test = 0;
    d->time = 0;
    d->memory = 0;
    d->solution_id = 0;
    d->lock_revision = 0;
}

Submit::Submit(const Submit &other)
    : TAbstractModel(), d(new SubmitObject(*other.d))
{ }

Submit::Submit(const SubmitObject &object)
    : TAbstractModel(), d(new SubmitObject(object))
{ }

Submit::~Submit()
{
    // If the reference count becomes 0,
    // the shared data object 'SubmitObject' is deleted.
}

int Submit::submitId() const
{
    return d->submit_id;
}

QString Submit::respCode() const
{
    return d->resp_code;
}

void Submit::setRespCode(const QString &respCode)
{
    d->resp_code = respCode;
}

int Submit::errorTest() const
{
    return d->error_test;
}

void Submit::setErrorTest(int errorTest)
{
    d->error_test = errorTest;
}

int Submit::time() const
{
    return d->time;
}

void Submit::setTime(int time)
{
    d->time = time;
}

int Submit::memory() const
{
    return d->memory;
}

void Submit::setMemory(int memory)
{
    d->memory = memory;
}

int Submit::solutionId() const
{
    return d->solution_id;
}

void Submit::setSolutionId(int solutionId)
{
    d->solution_id = solutionId;
}

int Submit::lockRevision() const
{
    return d->lock_revision;
}

Submit &Submit::operator=(const Submit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Submit Submit::create(const QString &respCode, int errorTest, int time, int memory, int solutionId)
{
    SubmitObject obj;
    obj.resp_code = respCode;
    obj.error_test = errorTest;
    obj.time = time;
    obj.memory = memory;
    obj.solution_id = solutionId;
    if (!obj.create()) {
        return Submit();
    }
    return Submit(obj);
}

Submit Submit::create(const QVariantMap &values)
{
    Submit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Submit Submit::get(int submitId)
{
    TSqlORMapper<SubmitObject> mapper;
    return Submit(mapper.findByPrimaryKey(submitId));
}

Submit Submit::get(int submitId, int lockRevision)
{
    TSqlORMapper<SubmitObject> mapper;
    TCriteria cri;
    cri.add(SubmitObject::SubmitId, submitId);
    cri.add(SubmitObject::LockRevision, lockRevision);
    return Submit(mapper.findFirst(cri));
}

int Submit::count()
{
    TSqlORMapper<SubmitObject> mapper;
    return mapper.findCount();
}

QList<Submit> Submit::getAll()
{
    return tfGetModelListByCriteria<Submit, SubmitObject>(TCriteria());
}

QJsonArray Submit::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<SubmitObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<SubmitObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Submit(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Submit::modelData()
{
    return d.data();
}

const TModelObject *Submit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Submit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Submit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Submit)
