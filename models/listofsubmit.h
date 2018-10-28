#ifndef LISTOFSUBMIT_H
#define LISTOFSUBMIT_H

#include <QObject>
#include <QAbstractListModel>
#include "submit.h"

class ListOfSubmit : public QAbstractListModel {

    Q_OBJECT

public:
    enum Roles {
        SubmitTimeRole = Qt::UserRole + 1,
        ProblemRole,
        RespCodeRole,
        MemoryRole,
        TimeRole,
        ErrorTestRole,
        PointsRole
    };

    ListOfSubmit(QObject *parent = Q_NULLPTR);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<QSharedPointer<Submit>> m_data;

};

#endif // LISTOFSUBMIT_H
