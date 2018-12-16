//#ifndef TABLEOFRESULT_H
//#define TABLEOFRESULT_H

//#include <QObject>
//#include <QAbstractTableModel>
//#include "shortcontest.h"

//class TableOfResult : public QAbstractTableModel {

//    Q_OBJECT

//public:
//    enum Roles {
//        ColorRole = Qt::UserRole + 1
//    };

//    TableOfResult(QObject *parent = Q_NULLPTR);

//    virtual int rowCount(const QModelIndex &parent) const;
//    virtual int columnCount(const QModelIndex &parent) const;
//    virtual QVariant data(const QModelIndex &index, int role) const;
//    virtual QHash<int, QByteArray> roleNames() const;

//    Q_INVOKABLE void add();
//    Q_INVOKABLE void removeAt(int index);

//private:
//    QList<QSharedPointer<ShortContest>> m_data;

//};

//#endif // TABLEOFRESULT_H
