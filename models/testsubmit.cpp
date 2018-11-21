#include <TreeFrogModel>
#include "testsubmit.h"
#include "testsubmitobject.h"

TestSubmit::TestSubmit()
    : TAbstractModel(), d(new TestSubmitObject())
{
    d->test_submit_id = 0;
    d->time = 0;
    d->memory = 0;
    d->test_id = 0;
    d->submit_id = 0;
    d->lock_revision = 0;
}

TestSubmit::TestSubmit(const TestSubmit &other)
    : TAbstractModel(), d(new TestSubmitObject(*other.d))
{ }

TestSubmit::TestSubmit(const TestSubmitObject &object)
    : TAbstractModel(), d(new TestSubmitObject(object))
{ }

TestSubmit::~TestSubmit()
{
    // If the reference count becomes 0,
    // the shared data object 'TestSubmitObject' is deleted.
}

int TestSubmit::testSubmitId() const
{
    return d->test_submit_id;
}

QString TestSubmit::verdict() const
{
    return d->verdict;
}

void TestSubmit::setVerdict(const QString &verdict)
{
    d->verdict = verdict;
}

int TestSubmit::time() const
{
    return d->time;
}

void TestSubmit::setTime(int time)
{
    d->time = time;
}

int TestSubmit::memory() const
{
    return d->memory;
}

void TestSubmit::setMemory(int memory)
{
    d->memory = memory;
}

int TestSubmit::testId() const
{
    return d->test_id;
}

void TestSubmit::setTestId(int testId)
{
    d->test_id = testId;
}

int TestSubmit::submitId() const
{
    return d->submit_id;
}

void TestSubmit::setSubmitId(int submitId)
{
    d->submit_id = submitId;
}

int TestSubmit::lockRevision() const
{
    return d->lock_revision;
}

TestSubmit &TestSubmit::operator=(const TestSubmit &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

TestSubmit TestSubmit::create(const QString &verdict, int time, int memory, int testId, int submitId)
{
    TestSubmitObject obj;
    obj.verdict = verdict;
    obj.time = time;
    obj.memory = memory;
    obj.test_id = testId;
    obj.submit_id = submitId;
    if (!obj.create()) {
        return TestSubmit();
    }
    return TestSubmit(obj);
}

TestSubmit TestSubmit::create(const QVariantMap &values)
{
    TestSubmit model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

TestSubmit TestSubmit::get(int testSubmitId)
{
    TSqlORMapper<TestSubmitObject> mapper;
    return TestSubmit(mapper.findByPrimaryKey(testSubmitId));
}

TestSubmit TestSubmit::get(int testSubmitId, int lockRevision)
{
    TSqlORMapper<TestSubmitObject> mapper;
    TCriteria cri;
    cri.add(TestSubmitObject::TestSubmitId, testSubmitId);
    cri.add(TestSubmitObject::LockRevision, lockRevision);
    return TestSubmit(mapper.findFirst(cri));
}

int TestSubmit::count()
{
    TSqlORMapper<TestSubmitObject> mapper;
    return mapper.findCount();
}

QList<TestSubmit> TestSubmit::getAll(int submitId, int limit, int offset)
{
    TSqlQueryORMapper<TestSubmitObject> mapper;
    QString queryStr = "SELECT ts.* FROM test_submit ts\n"
                       "JOIN test t on ts.test_id = t.test_id ";
    if (submitId) {
        queryStr += "WHERE submit_id = ? ";
        mapper.addBind(submitId);
    }
    queryStr += "ORDER BY t.in_problem_id ASC ";
    if (limit) {
        queryStr += "LIMIT ? ";
        mapper.addBind(limit);
    }

    if (offset) {
        queryStr += "OFFSET ? ";
        mapper.addBind(offset);
    }

    mapper.prepare(queryStr);
    mapper.exec();

    QList<TestSubmit> result;
    TSqlQueryORMapperIterator<TestSubmitObject> it(mapper);
    while (it.hasNext()) {
        result << TestSubmit(it.next());
    }

    return result;
}

QJsonArray TestSubmit::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<TestSubmitObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<TestSubmitObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(TestSubmit(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *TestSubmit::modelData()
{
    return d.data();
}

const TModelObject *TestSubmit::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const TestSubmit &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, TestSubmit &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

QVariantMap TestSubmit::getVariantMapLight() const {
    QVariantMap result;
    result["verdict"] = verdict().toInt();
    result["time"] = time();
    result["memory"] = memory();

    return result;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(TestSubmit)
