#include <TreeFrogModel>
#include "test.h"
#include "testobject.h"

Test::Test()
    : TAbstractModel(), d(new TestObject())
{
    d->test_id = 0;
    d->problem_id = 0;
    d->lock_revision = 0;
}

Test::Test(const Test &other)
    : TAbstractModel(), d(new TestObject(*other.d))
{ }

Test::Test(const TestObject &object)
    : TAbstractModel(), d(new TestObject(object))
{ }

Test::~Test()
{
    // If the reference count becomes 0,
    // the shared data object 'TestObject' is deleted.
}

int Test::testId() const
{
    return d->test_id;
}

QString Test::input() const
{
    return d->input;
}

void Test::setInput(const QString &input)
{
    d->input = input;
}

QString Test::output() const
{
    return d->output;
}

void Test::setOutput(const QString &output)
{
    d->output = output;
}

int Test::problemId() const
{
    return d->problem_id;
}

void Test::setProblemId(int problemId)
{
    d->problem_id = problemId;
}

int Test::lockRevision() const
{
    return d->lock_revision;
}

Test &Test::operator=(const Test &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Test Test::create(const QString &input, const QString &output, int problemId)
{
    TestObject obj;
    obj.input = input;
    obj.output = output;
    obj.problem_id = problemId;
    if (!obj.create()) {
        return Test();
    }
    return Test(obj);
}

Test Test::create(const QVariantMap &values)
{
    Test model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Test Test::get(int testId)
{
    TSqlORMapper<TestObject> mapper;
    return Test(mapper.findByPrimaryKey(testId));
}

Test Test::get(int testId, int lockRevision)
{
    TSqlORMapper<TestObject> mapper;
    TCriteria cri;
    cri.add(TestObject::TestId, testId);
    cri.add(TestObject::LockRevision, lockRevision);
    return Test(mapper.findFirst(cri));
}

int Test::count()
{
    TSqlORMapper<TestObject> mapper;
    return mapper.findCount();
}

QList<Test> Test::getAll()
{
    return tfGetModelListByCriteria<Test, TestObject>(TCriteria());
}

QJsonArray Test::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<TestObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<TestObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Test(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Test::modelData()
{
    return d.data();
}

const TModelObject *Test::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Test &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Test &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Test)
