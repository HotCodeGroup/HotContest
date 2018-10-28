#ifndef LISTOFPARTICIPANTS_H
#define LISTOFPARTICIPANTS_H

#include <QObject>
#include <QAbstractListModel>
#include "user.h"

class ListOfParticipants : public QAbstractListModel {

    Q_OBJECT

public:
    enum Roles {
        Nickname = Qt::UserRole + 1
    };

    ListOfParticipants(QObject *parent = Q_NULLPTR);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<QSharedPointer<User>> m_data;

};

#endif // LISTOFPARTICIPANTS_H
