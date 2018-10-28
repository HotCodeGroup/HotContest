#ifndef LISTOFSHORTCONTEST_H
#define LISTOFSHORTCONTEST_H

#include <QObject>
#include <QAbstractListModel>
#include "shortcontest.h"

class ListOfShortContest : public QAbstractListModel {

    Q_OBJECT

public:
    enum Roles {
        TitleRole = Qt::UserRole + 1,
        ResultRole,
        ParticipantsRole
    };

    ListOfShortContest(QObject *parent = Q_NULLPTR);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void add();
    Q_INVOKABLE void removeAt(int index);

private:
    QList<QSharedPointer<ShortContest>> m_data;

};

#endif // LISTOFSHORTCONTEST_H
