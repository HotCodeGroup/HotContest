#ifndef PROFILE_H
#define PROFILE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ProfileObject;
class QJsonArray;


class T_MODEL_EXPORT Profile : public TAbstractModel
{
public:
    Profile();
    Profile(const Profile &other);
    Profile(const ProfileObject &object);
    ~Profile();

    int userId() const;
    QString firstName() const;
    void setFirstName(const QString &firstName);
    QString lastName() const;
    void setLastName(const QString &lastName);
    QString nickname() const;
    void setNickname(const QString &nickname);
    QString email() const;
    void setEmail(const QString &email);
    QString password() const;
    void setPassword(const QString &password);
    QDateTime dateJoined() const;
    void setDateJoined(const QDateTime &dateJoined);
    bool isActive() const;
    void setIsActive(const bool &isActive);
    int lockRevision() const;
    Profile &operator=(const Profile &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Profile create(const QString &firstName, const QString &lastName, const QString &nickname, const QString &email, const QString &password, const QDateTime &dateJoined, const bool &isActive);
    static Profile create(const QVariantMap &values);
    static Profile get(int userId);
    static Profile get(int userId, int lockRevision);
    static int count();
    static QList<Profile> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ProfileObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Profile &model);
    friend QDataStream &operator>>(QDataStream &ds, Profile &model);
};

Q_DECLARE_METATYPE(Profile)
Q_DECLARE_METATYPE(QList<Profile>)

#endif // PROFILE_H
