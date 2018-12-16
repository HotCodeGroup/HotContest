#ifndef LISTOFTESTSUBMIT_H
#define LISTOFTESTSUBMIT_H

#include <QObject>
#include <QAbstractListModel>
#include "src/models/TestSubmit/testsubmit.h"
#include <QtQml>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class ListOfTestSubmit : public QAbstractListModel {

    Q_OBJECT
    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)
    Q_PROPERTY(StateInfo* state READ getState NOTIFY stateChanged)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        VerdictRole,
        MemoryRole,
        TimeRole
    };
    static ListOfTestSubmit* instance();
    ~ListOfTestSubmit();

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    int getSize() const;
    StateInfo* getState() const;

    Q_INVOKABLE void add(TestSubmit* testSubmit);
    Q_INVOKABLE static void sendRequest(int contestId, int submitId);
    void clear();

signals:
    void sizeChanged(int);
    void stateChanged(StateInfo*);


private:
    static void TestSubmitsController(const QJsonObject &obj);

    static ListOfTestSubmit* p_instance;
    ListOfTestSubmit(QObject *parent = Q_NULLPTR);

    QList<TestSubmit*> m_data;
    StateInfo* state;

};

#endif // LISTOFTESTSUBMIT_H
