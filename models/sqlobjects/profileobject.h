#ifndef PROFILEOBJECT_H
#define PROFILEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ProfileObject : public TSqlObject, public QSharedData
{
public:
    int user_id {0};
    QString first_name;
    QString last_name;
    QString username;
    QString email;
    QString password;
    QDateTime created_at;
    bool is_active;
    int lock_revision {0};

    enum PropertyIndex {
        UserId = 0,
        FirstName,
        LastName,
        Username,
        Email,
        Password,
        CreatedAt,
        IsActive,
        LockRevision,
    };

    int primaryKeyIndex() const override { return UserId; }
    int autoValueIndex() const override { return UserId; }
    QString tableName() const override { return QLatin1String("profile"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int user_id READ getuser_id WRITE setuser_id)
    T_DEFINE_PROPERTY(int, user_id)
    Q_PROPERTY(QString first_name READ getfirst_name WRITE setfirst_name)
    T_DEFINE_PROPERTY(QString, first_name)
    Q_PROPERTY(QString last_name READ getlast_name WRITE setlast_name)
    T_DEFINE_PROPERTY(QString, last_name)
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(bool is_active READ getis_active WRITE setis_active)
    T_DEFINE_PROPERTY(bool, is_active)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // PROFILEOBJECT_H
