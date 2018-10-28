#ifndef SUBMIT_H
#define SUBMIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

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
    QString respCode() const;
    void setRespCode(const QString &respCode);
    int errorTest() const;
    void setErrorTest(int errorTest);
    int time() const;
    void setTime(int time);
    int memory() const;
    void setMemory(int memory);
    int solutionId() const;
    void setSolutionId(int solutionId);
    int lockRevision() const;
    Submit &operator=(const Submit &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Submit create(const QString &respCode, int errorTest, int time, int memory, int solutionId);
    static Submit create(const QVariantMap &values);
    static Submit get(int submitId);
    static Submit get(int submitId, int lockRevision);
    static int count();
    static QList<Submit> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<SubmitObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Submit &model);
    friend QDataStream &operator>>(QDataStream &ds, Submit &model);
};

Q_DECLARE_METATYPE(Submit)
Q_DECLARE_METATYPE(QList<Submit>)

#endif // SUBMIT_H
