#ifndef SUBMIT_H
#define SUBMIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>
#include <QtSql/QSqlRecord>

class TModelObject;
class SubmitObject;
class QJsonArray;


class T_MODEL_EXPORT Submit : public TAbstractModel
{
public:
    Submit();
    Submit(const Submit &other);
    Submit(const SubmitObject &object);
    ~Submit();

    int submitId() const;
    int respCode() const;
    void setRespCode(int respCode);
    int errorTest() const;
    void setErrorTest(int errorTest);
    int time() const;
    void setTime(int time);
    int memory() const;
    void setMemory(int memory);
    int solutionId() const;
    void setSolutionId(int solutionId);
    int lockRevision() const;
    int points() const;
    void setPoints(int points);
    Submit &operator=(const Submit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Submit create(int respCode, int errorTest, int t, int memory, int solutionId, int points);
    static Submit create(const QVariantMap &values);
    static Submit get(int submitId);
    static Submit get(int submitId, int lockRevision);
    static int count();
    static int countUserContestSubmits(int contestId, int userId,  int problemId);
    static QList<Submit> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getUserContestSubmitsJson(int contestId, int userId, int limit, int offset, int problemId);

    static QList<QVariant> getFullInfo(int submitId, int testsLimit);

private:
    static QVariantMap fullDataFromRecord(const QSqlRecord &record);

    QSharedDataPointer<SubmitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Submit &model);
    friend QDataStream &operator>>(QDataStream &ds, Submit &model);
};

Q_DECLARE_METATYPE(Submit)
Q_DECLARE_METATYPE(QList<Submit>)

#endif // SUBMIT_H
