#ifndef LISTOFSHORTCONTEST_H
#define LISTOFSHORTCONTEST_H

#include <QObject>
#include <QAbstractListModel>
#include "src/models/ShortContest/shortcontest.h"
#include <QtQml>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"


class ListOfShortContest : public QAbstractListModel {

    Q_OBJECT
    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)
    Q_PROPERTY(StateInfo* state READ getState NOTIFY stateChanged)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        TitleRole,
        ResultRole,
        ParticipantsRole
    };
    static ListOfShortContest* instance();
    ~ListOfShortContest();

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    int getSize() const;
    StateInfo* getState() const;

    Q_INVOKABLE void add(ShortContest* contest);
    Q_INVOKABLE static void sendRequest();

signals:
    void sizeChanged(int);
    void stateChanged(StateInfo*);

private:
    static void ShortContestController(const QJsonObject &obj);

    static ListOfShortContest* p_instance;
    ListOfShortContest(QObject* parent = Q_NULLPTR);

    QList<ShortContest*> m_data;
    StateInfo* state;
};

#endif // LISTOFSHORTCONTEST_H
