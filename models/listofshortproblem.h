#ifndef LISTOFSHORTPROBLEM_H
#define LISTOFSHORTPROBLEM_H

#include <QObject>
#include <QAbstractListModel>
#include "shortproblem.h"

class ListOfShortProblem : public QAbstractListModel {

    Q_OBJECT

public:
    enum Roles {
        TitleRole = Qt::UserRole + 1,
        CompliteRole,
        PointsRole
    };

    ListOfShortProblem(QObject *parent = Q_NULLPTR);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<QSharedPointer<ShortProblem>> m_data;

};

#endif // LISTOFSHORTPROBLEM_H
