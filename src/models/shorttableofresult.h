#ifndef SHORTTABLEOFRESULT_H
#define SHORTTABLEOFRESULT_H

#include <QObject>
#include <QAbstractTableModel>
#include "shortcontest.h"

class ShortTableOfResult : public QAbstractTableModel {

    Q_OBJECT

public:
    enum Roles {
        ColorRole = Qt::UserRole + 1
    };

    ShortTableOfResult(QObject *parent = Q_NULLPTR);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<ShortContest*> m_data;

};

#endif // SHORTTABLEOFRESULT_H
