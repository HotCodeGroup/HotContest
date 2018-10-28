#ifndef PROBLEM_H
#define PROBLEM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ProblemObject;
class QJsonArray;


class T_MODEL_EXPORT Problem : public TAbstractModel
{
public:
    Problem();
    Problem(const Problem &other);
    Problem(const ProblemObject &object);
    ~Problem();

    int problemId() const;
    QString title() const;
    void setTitle(const QString &title);
    QString description() const;
    void setDescription(const QString &description);
    int timeLimit() const;
    void setTimeLimit(int timeLimit);
    int memoryLimit() const;
    void setMemoryLimit(int memoryLimit);
    int triesLeft() const;
    void setTriesLeft(int triesLeft);
    int points() const;
    void setPoints(int points);
    int penaltyTry() const;
    void setPenaltyTry(int penaltyTry);
    int penaltyTime() const;
    void setPenaltyTime(int penaltyTime);
    int contestId() const;
    void setContestId(int contestId);
    int lockRevision() const;
    Problem &operator=(const Problem &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Problem create(const QString &title, const QString &description, int timeLimit, int memoryLimit, int triesLeft, int points, int penaltyTry, int penaltyTime, int contestId);
    static Problem create(const QVariantMap &values);
    static Problem get(int problemId);
    static Problem get(int problemId, int lockRevision);
    static int count();
    static QList<Problem> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ProblemObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Problem &model);
    friend QDataStream &operator>>(QDataStream &ds, Problem &model);
};

Q_DECLARE_METATYPE(Problem)
Q_DECLARE_METATYPE(QList<Problem>)

#endif // PROBLEM_H
