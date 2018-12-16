#ifndef LISTOFPARTICIPANTS_H
#define LISTOFPARTICIPANTS_H

#include <QObject>
#include <QAbstractListModel>
#include "src/models/Participant/participant.h"
#include <QtQml>
#include "src/requester/requester.h"
#include "src/tester.h"
#include "src/utils/stateinfo.h"

class ListOfParticipants : public QAbstractListModel {

    Q_OBJECT
    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)
    Q_PROPERTY(StateInfo* state READ getState NOTIFY stateChanged)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NicknameRole
    };
    static ListOfParticipants* instance();
    ~ListOfParticipants();

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    int getSize() const;
    StateInfo* getState() const;

    Q_INVOKABLE void add(Participant* participant);
    Q_INVOKABLE static void sendRequest(int contestId);
    void clear();

signals:
    void sizeChanged(int);
    void stateChanged(StateInfo*);

private:
    static void ParticipantsController(const QJsonObject &obj);

    static ListOfParticipants* p_instance;
    ListOfParticipants(QObject *parent = Q_NULLPTR);

    QList<Participant*> m_data;
    StateInfo* state;

};

#endif // LISTOFPARTICIPANTS_H
