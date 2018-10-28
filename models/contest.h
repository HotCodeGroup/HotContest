#ifndef CONTEST_H
#define CONTEST_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ContestObject;
class QJsonArray;


class T_MODEL_EXPORT Contest : public TAbstractModel
{
public:
    Contest();
    Contest(const Contest &other);
    Contest(const ContestObject &object);
    ~Contest();

    int contestId() const;
    QString title() const;
    void setTitle(const QString &title);
    QString description() const;
    void setDescription(const QString &description);
    QDateTime startTime() const;
    void setStartTime(const QDateTime &startTime);
    QDateTime finishTime() const;
    void setFinishTime(const QDateTime &finishTime);
    bool isPrivate() const;
    void setIsPrivate(const bool &isPrivate);
    bool isActive() const;
    void setIsActive(const bool &isActive);
    int lockRevision() const;
    Contest &operator=(const Contest &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Contest create(const QString &title, const QString &description, const QDateTime &startTime, const QDateTime &finishTime, const bool &isPrivate, const bool &isActive);
    static Contest create(const QVariantMap &values);
    static Contest get(int contestId);
    static Contest get(int contestId, int lockRevision);
    static int count();
    static QList<Contest> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ContestObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Contest &model);
    friend QDataStream &operator>>(QDataStream &ds, Contest &model);
};

Q_DECLARE_METATYPE(Contest)
Q_DECLARE_METATYPE(QList<Contest>)

#endif // CONTEST_H
