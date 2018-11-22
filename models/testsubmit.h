#ifndef TESTSUBMIT_H
#define TESTSUBMIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TestSubmitObject;
class QJsonArray;


class T_MODEL_EXPORT TestSubmit : public TAbstractModel
{
public:
    TestSubmit();
    TestSubmit(const TestSubmit &other);
    TestSubmit(const TestSubmitObject &object);
    ~TestSubmit();

    int testSubmitId() const;
    QString verdict() const;
    void setVerdict(const QString &verdict);
    int time() const;
    void setTime(int time);
    int memory() const;
    void setMemory(int memory);
    int testId() const;
    void setTestId(int testId);
    int submitId() const;
    void setSubmitId(int submitId);
    int lockRevision() const;
    TestSubmit &operator=(const TestSubmit &other);

    QVariantMap getVariantMapLight() const;

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static TestSubmit create(const QString &verdict, int time, int memory, int testId, int submitId);
    static TestSubmit create(const QVariantMap &values);
    static TestSubmit get(int testSubmitId);
    static TestSubmit get(int testSubmitId, int lockRevision);
    static int count();
    static int countForSubmit(int submitId);
    static QList<TestSubmit> getAll(int submitId = 0,  int limit = 0, int offset = 0);
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<TestSubmitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const TestSubmit &model);
    friend QDataStream &operator>>(QDataStream &ds, TestSubmit &model);
};

Q_DECLARE_METATYPE(TestSubmit)
Q_DECLARE_METATYPE(QList<TestSubmit>)

#endif // TESTSUBMIT_H
