#ifndef SHORTPROBLEM_H
#define SHORTPROBLEM_H

#include <QString>
#include <QObject>

class ShortProblem : public QObject {

    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(const QString& title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int curPoints READ getCurPoints WRITE setCurPoints NOTIFY curPointsChanged)
    Q_PROPERTY(bool isComplite READ getIsComplite WRITE setIsComplite NOTIFY isCompliteChanged)

public:
    ShortProblem(int id = 0, const QString& title = "",
                 int curPoints = 0, bool isComplite = false);
    ~ShortProblem();

    int getId() const;
    void setId(int id);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    int getCurPoints() const;
    void setCurPoints(int curPoints);

    bool getIsComplite() const;
    void setIsComplite(bool isComplite);

signals:
    void idChanged(int);
    void titleChanged(const QString&);
    void curPointsChanged(int);
    void isCompliteChanged(bool);

private:
    int id;
    QString title;
    int curPoints;
    bool isComplite;
};

#endif // SHORTPROBLEM_H
