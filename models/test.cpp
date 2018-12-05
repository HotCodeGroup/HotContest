#include <TreeFrogModel>
#include "test.h"
#include "testobject.h"

QString Test::testsRoot = "/home/gdvfox/StudyMaterials/CPP_Programming/HotContestData/";
int Test::symbols_limit = 100;

Test::Test()
    : TAbstractModel(), d(new TestObject())
{
    d->test_id = 0;
    d->lock_revision = 0;
    d->problem_id = 0;
    d->in_problem_id = 0;
}

Test::Test(const Test &other)
    : TAbstractModel(), d(new TestObject(*other.d))
{ }

Test::Test(const TestObject &object)
    : TAbstractModel(), d(new TestObject(object))
{
    QFile fileInput(Test::testsRoot + object.input);
    if(!fileInput.open(QIODevice::ReadOnly)) {
        d->test_id = 0;
    }

    QTextStream in(&fileInput);
    inputPreview = in.read(Test::symbols_limit).trimmed();

    QFile fileOutput(Test::testsRoot + object.output);
    if(!fileOutput.open(QIODevice::ReadOnly)) {
        d->test_id = 0;
    }

    QTextStream out(&fileOutput);
    outputPreview = out.read(Test::symbols_limit).trimmed();
}

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

int Test::lockRevision() const
{
    return d->lock_revision;
}

int Test::problemId() const
{
    return d->problem_id;
}

void Test::setProblemId(int problemId)
{
    d->problem_id = problemId;
}

int Test::inProblemId() const
{
    return d->in_problem_id;
}

void Test::setInProblemId(int inProblemId)
{
    d->in_problem_id = inProblemId;
}

Test &Test::operator=(const Test &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Test Test::create(const QString &input, const QString &output, int problemId, int inProblemId)
{
    TestObject obj;
    obj.input = input;
    obj.output = output;
    obj.problem_id = problemId;
    obj.in_problem_id = inProblemId;
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

QVariantMap Test::toVariantMap() const {
    auto super_map = TAbstractModel::toVariantMap();
    super_map["inputPreview"] = inputPreview;
    super_map["outputPreview"] = outputPreview;

    return super_map;
}

QVariantMap Test::toVariantMapLight() const {
    QVariantMap result;

    result["testId"] = testId();
    result["inProblemId"] = inProblemId();
    result["inputPreview"] = inputPreview;
    result["outputPreview"] = outputPreview;

    return result;
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

Test Test::getWithProblem(int problemId, int testPos) {
    TSqlORMapper<TestObject> mapper;
    TCriteria cri;
    cri.add(TestObject::ProblemId, problemId);
    cri.add(TestObject::InProblemId, testPos);
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

QJsonArray Test::getLightListJson(int contestId, int problemId) {
    QJsonArray array;
    TSqlORMapper<TestObject> mapper;

    TCriteria cri;
    cri.add(TestObject::ProblemId, problemId);
    mapper.sort(TestObject::InProblemId, Qt::SortOrder::AscendingOrder);

    if (mapper.find(cri) > 0) {
        for (TSqlORMapperIterator<TestObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Test(i.next()).toVariantMapLight())));
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
