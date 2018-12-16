#ifndef LISTOFSUBMIT_H
#define LISTOFSUBMIT_H

#include <QObject>
#include <QAbstractListModel>
#include "src/models/Submit/submit.h"
#include <QtQml>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class ListOfSubmit : public QAbstractListModel {

    Q_OBJECT
    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)
    Q_PROPERTY(StateInfo* state READ getState NOTIFY stateChanged)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        SubmitTimeRole,
        ProblemRole,
        RespCodeRole,
        MemoryRole,
        TimeRole,
        ErrorTestRole,
        PointsRole
    };
    static ListOfSubmit* instance();
    ~ListOfSubmit();

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    int getSize() const;
    StateInfo* getState() const;

    Q_INVOKABLE void add(Submit* submit);
    Q_INVOKABLE static void sendShortRequest(int contestId, int problemId);
    Q_INVOKABLE static void sendRequest(int contestId);
    void clear();

signals:
    void sizeChanged(int);
    void stateChanged(StateInfo*);

private:
    static void SubmitsController(const QJsonObject &obj);

    static ListOfSubmit* p_instance;
    ListOfSubmit(QObject *parent = Q_NULLPTR);

    QList<Submit*> m_data;
    StateInfo* state;

};

#endif // LISTOFSUBMIT_H
