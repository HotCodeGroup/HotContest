#include <QVariant>
#include "listofparticipants.h"
#include <QtDebug>

ListOfParticipants* ListOfParticipants::p_instance = Q_NULLPTR;

ListOfParticipants::ListOfParticipants(QObject *parent) :
    QAbstractListModel(parent)
{
    state = new StateInfo();
}

ListOfParticipants* ListOfParticipants::instance() {
    if(!p_instance)
        p_instance = new ListOfParticipants();
    return p_instance;
}

ListOfParticipants::~ListOfParticipants() {
    delete state;
}

int ListOfParticipants::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

QVariant ListOfParticipants::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case IdRole:
        return m_data[index.row()]->getId();
    case NicknameRole:
        return m_data[index.row()]->getUsername();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ListOfParticipants::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole] = "participantId";
    roles[NicknameRole] = "username";

    return roles;
}

StateInfo* ListOfParticipants::getState() const {
    return state;
}

int ListOfParticipants::getSize() const {
    return m_data.size();
}

void ListOfParticipants::add(Participant* participant) {
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(participant);
    endInsertRows();
    emit sizeChanged(m_data.size());
}

void ListOfParticipants::clear() {
    beginRemoveRows(QModelIndex(), 0, m_data.size() - 1);
    m_data.clear();
    endRemoveRows();
}

void ListOfParticipants::ParticipantsController(const QJsonObject &obj) {
    if (obj.contains("array_data") && obj["array_data"].isArray()) {
        QJsonArray participantsArray = obj["array_data"].toArray();
        ListOfParticipants::instance()->clear();

        for (int participantIndex = 0; participantIndex < participantsArray.size(); ++participantIndex) {
            auto participant = new Participant();

            participant->setId(participantIndex + 1);

            participant->setUsername(participantsArray[participantIndex].toString());

            ListOfParticipants::instance()->add(participant);
        }
    }
    ListOfParticipants::instance()->state->setIsLoading(false);
}

void ListOfParticipants::sendRequest(int contestId) {
    ListOfParticipants::instance()->state->setIsLoading(true);
    Requester::instance()->sendRequest("contests/" + QString::number(contestId) + "/participants", ParticipantsController, nullptr);
//    Tester test;
//    test.sendRequestOnListParticipants(ParticipantsController);
}
