#ifndef SOLUTION_H
#define SOLUTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class SolutionObject;
class QJsonArray;


class T_MODEL_EXPORT Solution : public TAbstractModel
{
public:
    Solution();
    Solution(const Solution &other);
    Solution(const SolutionObject &object);
    ~Solution();

    int solutionId() const;
    QString srcFile() const;
    void setSrcFile(const QString &srcFile);
    QDateTime submitTime() const;
    void setSubmitTime(const QDateTime &submitTime);
    int problemId() const;
    void setProblemId(int problemId);
    int userId() const;
    void setUserId(int userId);
    int lockRevision() const;
    Solution &operator=(const Solution &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Solution create(const QString &srcFile, const QDateTime &submitTime, int problemId, int userId);
    static Solution create(const QVariantMap &values);
    static Solution get(int solutionId);
    static Solution get(int solutionId, int lockRevision);
    static int count();
    static QList<Solution> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<SolutionObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Solution &model);
    friend QDataStream &operator>>(QDataStream &ds, Solution &model);
};

Q_DECLARE_METATYPE(Solution)
Q_DECLARE_METATYPE(QList<Solution>)

#endif // SOLUTION_H
