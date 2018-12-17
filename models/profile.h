#ifndef PROFILE_H
#define PROFILE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

class TModelObject;
class ProfileObject;
class QJsonArray;


class T_MODEL_EXPORT Profile : public TAbstractUser, public TAbstractModel
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
    QString username() const;
    void setUsername(const QString &username);
    QString email() const;
    void setEmail(const QString &email);
    QString password() const;
    void setPassword(const QString &password);
    QDateTime createdAt() const;
    bool isActive() const;
    void setIsActive(const bool &isActive);
    int lockRevision() const;
    void updateProperties(const QVariantMap &value);
    QVariantMap toVariantMapLight() const;

    QString identityKey() const { return username(); }
    Profile &operator=(const Profile &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Profile authenticate(const QString &username, const QString &password);
    static Profile create(const QString &firstName, const QString &lastName, const QString &username, const QString &email, const QString &password, const bool &isActive);
    static Profile create(QVariantMap &values);
    static Profile get(int userId);
    static Profile get(int userId, int lockRevision);
    static Profile getByUsername(const QString &usrname);
    static Profile getByEmail(const QString &email);
    static int count();
    static QList<Profile> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ProfileObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
    friend QDataStream &operator<<(QDataStream &ds, const Profile &model);
    friend QDataStream &operator>>(QDataStream &ds, Profile &model);
};

Q_DECLARE_METATYPE(Profile)
Q_DECLARE_METATYPE(QList<Profile>)

#endif // PROFILE_H
