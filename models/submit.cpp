#include <TreeFrogModel>
#include "submit.h"
#include "submitobject.h"
#include "testsubmit.h"

Submit::Submit()
    : TAbstractModel(), d(new SubmitObject())
{
    d->submit_id = 0;
    d->resp_code = 0;
    d->error_test = 0;
    d->time = 0;
    d->memory = 0;
    d->solution_id = 0;
    d->lock_revision = 0;
    d->points = 0;
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

int Submit::respCode() const
{
    return d->resp_code;
}

void Submit::setRespCode(int respCode)
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

int Submit::points() const
{
    return d->points;
}

void Submit::setPoints(int points)
{
    d->points = points;
}

Submit &Submit::operator=(const Submit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Submit Submit::create(int respCode, int errorTest, int time, int memory, int solutionId, int points)
{
    SubmitObject obj;
    obj.resp_code = respCode;
    obj.error_test = errorTest;
    obj.time = time;
    obj.memory = memory;
    obj.solution_id = solutionId;
    obj.points = points;
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

QVariantMap Submit::fullDataFromRecord(const QSqlRecord &record) {
    QVariantMap result;

    result["submitId"] = record.value(0).toInt();
    result["problemId"] = record.value(1).toInt();
    result["sendTime"] = record.value(2).toDateTime();
    result["result"] = record.value(3).toInt();
    result["testError"] = record.value(4).toInt();
    result["time"] = record.value(5).toInt();
    result["memory"] = record.value(6).toInt();
    result["points"] = record.value(7).toInt();

    return result;
}

QVariantMap Submit::getFullInfo(int submitId) {
    TSqlQuery query;
    query.prepare("SELECT su.submit_id,\n"
                  "       so.problem_id,\n"
                  "       so.submit_time,\n"
                  "       su.resp_code,\n"
                  "       su.error_test,\n"
                  "       su.time,\n"
                  "       su.memory,\n"
                  "       su.points\n"
                  "FROM submit su\n"
                  "       JOIN solution so on su.solution_id = so.solution_id\n"
                  "WHERE su.submit_id = ?;").addBind(submitId).exec();


    if (!query.next()) {
        return QVariantMap();
    }

    QVariantMap result(fullDataFromRecord(query.record()));
    QList<QVariant> testSubmitShortList;
    auto testSubmitList = TestSubmit::getAll(submitId);
    for (const auto &testSubmit : testSubmitList) {
        testSubmitShortList << testSubmit.getVariantMapLight();
    }

    result["tests"] = testSubmitShortList;

    return result;
}



// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Submit)
