#ifndef SOLUTION_H
#define SOLUTION_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>
#include <TMultipartFormData>

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
    int userId() const;
    void setUserId(int userId);
    int lockRevision() const;
    int problemId() const;
    void setProblemId(int problemId);
    Solution &operator=(const Solution &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Solution create(TMultipartFormData &srcFile, int user_id, int contest_id, int problem_pos);
    static Solution create(const QString &srcFile, const QDateTime &submitTime, int userId, int problemId);
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
    static const QString generateFileName(); 

    friend QDataStream &operator<<(QDataStream &ds, const Solution &model);
    friend QDataStream &operator>>(QDataStream &ds, Solution &model);

    static const QString src_root;
};

Q_DECLARE_METATYPE(Solution)
Q_DECLARE_METATYPE(QList<Solution>)

#endif // SOLUTION_H
