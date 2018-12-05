#ifndef SHORTCONTEST_H
#define SHORTCONTEST_H

#include <QString>
#include <QObject>

class ShortContest : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int countOfParticipants READ getCountOfParticipants WRITE setCountOfParticipants NOTIFY countOfParticipantsChanged)
    Q_PROPERTY(bool isActive READ getIsActive WRITE setIsActive NOTIFY isActiveChanged)

public:
    ShortContest(int id = 0, const QString& title = "",
                 int countOfParticipants = 0, bool isActive = true);
    ~ShortContest();

    int getId() const;
    void setId(int id);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    int getCountOfParticipants() const;
    void setCountOfParticipants(int countOfParticipants);

    bool getIsActive() const;
    void setIsActive(bool isActive);

signals:
    void idChanged(int);
    void titleChanged(const QString&);
    void countOfParticipantsChanged(int);
    void isActiveChanged(bool);

private:
    int id;
    QString title;
    int countOfParticipants;
    bool isActive;
};

#endif // SHORTCONTEST_H
