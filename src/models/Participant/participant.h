#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QObject>
#include <QString>
#include <QDateTime>

class Participant : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& username READ getUsername WRITE setUsername NOTIFY usernameChanged)

public:
    Participant(int id = 0, const QString& username = "");
    ~Participant();

    int getId() const;
    void setId(int id);

    const QString& getUsername() const;
    void setUsername(const QString& username);

signals:
    void idChanged(int);
    void usernameChanged(const QString&);

private:
    int id;
    QString username;
};

#endif // PARTICIPANT_H
