#ifndef TEST_H
#define TEST_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TestObject;
class QJsonArray;


class T_MODEL_EXPORT Test : public TAbstractModel
{
public:
    Test();
    Test(const Test &other);
    Test(const TestObject &object);
    ~Test();

    int testId() const;
    QString input() const;
    void setInput(const QString &input);
    QString output() const;
    void setOutput(const QString &output);
    int lockRevision() const;
    int problemId() const;
    void setProblemId(int problemId);
    int inProblemId() const;
    void setInProblemId(int inProblemId);
    QString getInputPreview() const;
    QString getOutputPreview() const;
    Test &operator=(const Test &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    QVariantMap toVariantMap() const override;
    QVariantMap toVariantMapLight() const;

    static Test create(const QString &input, const QString &output, int problemId, int inProblemId);
    static Test create(const QVariantMap &values);
    static Test get(int testId);
    static Test get(int testId, int lockRevision);
    static Test getWithProblem(int problemId, int testPos);
    static int count();
    static QList<Test> getAll();
    static QJsonArray getAllJson();

    static QJsonArray getLightListJson(int contestId, int problemId);
private:
    static QString testsRoot;
    static int symbols_limit;

    QSharedDataPointer<TestObject> d;
    QString inputPreview;
    QString outputPreview;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Test &model);
    friend QDataStream &operator>>(QDataStream &ds, Test &model);
};

Q_DECLARE_METATYPE(Test)
Q_DECLARE_METATYPE(QList<Test>)

#endif // TEST_H
