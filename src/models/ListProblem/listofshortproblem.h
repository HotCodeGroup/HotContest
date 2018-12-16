#ifndef LISTOFSHORTPROBLEM_H
#define LISTOFSHORTPROBLEM_H

#include <QObject>
#include <QAbstractListModel>
#include "src/models/ShortProblem/shortproblem.h"
#include <QtQml>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class ListOfShortProblem : public QAbstractListModel {

    Q_OBJECT
    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)
    Q_PROPERTY(StateInfo* state READ getState NOTIFY stateChanged)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        TitleRole,
        CompliteRole,
        PointsRole
    };
    static ListOfShortProblem* instance();
    ~ListOfShortProblem();

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    int getSize() const;
    StateInfo* getState() const;

    Q_INVOKABLE void add(ShortProblem* contest);
    void clear();
    Q_INVOKABLE static void sendRequest(int contestId);

signals:
    void sizeChanged(int);
    void stateChanged(StateInfo*);

private:
    static void ShortProblemController(const QJsonObject &obj);

    static ListOfShortProblem* p_instance;
    ListOfShortProblem(QObject *parent = Q_NULLPTR);

    QList<ShortProblem*> m_data;
    StateInfo* state;
};

#endif // LISTOFSHORTPROBLEM_H
