#include <QVariant>
#include "listofshortcontest.h"
#include <QtDebug>

ListOfShortContest* ListOfShortContest::p_instance = Q_NULLPTR;

ListOfShortContest::ListOfShortContest(QObject *parent) :
    QAbstractListModel(parent)
{
    state = new StateInfo();
}

ListOfShortContest* ListOfShortContest::instance() {
    if(!p_instance)
        p_instance = new ListOfShortContest();
    return p_instance;
}

ListOfShortContest::~ListOfShortContest() {
    delete state;
}

int ListOfShortContest::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

QVariant ListOfShortContest::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case IdRole:
        return m_data[index.row()]->getId();
    case TitleRole:
        return m_data[index.row()]->getTitle();
    case ResultRole:
        return m_data[index.row()]->getIsActive();
    case ParticipantsRole:
        return m_data[index.row()]->getCountOfParticipants();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ListOfShortContest::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole] = "contestId";
    roles[TitleRole] = "titleStr";
    roles[ResultRole] = "isActive";
    roles[ParticipantsRole] = "countOfParticipants";

    return roles;
}

StateInfo* ListOfShortContest::getState() const {
    return state;
}

int ListOfShortContest::getSize() const {
    return m_data.size();
}

void ListOfShortContest::add(ShortContest* contest) {
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(contest);
    endInsertRows();
    emit sizeChanged(m_data.size());
}

void ListOfShortContest::ShortContestController(const QJsonObject &obj) {
    if (obj.contains("array_data") && obj["array_data"].isArray()) {
        QJsonArray contestsArray = obj["array_data"].toArray();


        for (int contestIndex = 0; contestIndex < contestsArray.size(); ++contestIndex) {
            QJsonObject contestObject = contestsArray[contestIndex].toObject();
            auto shortContest = new ShortContest();

            if (contestObject.contains("contestId") && contestObject["contestId"].isDouble())
                shortContest->setId(contestObject["contestId"].toInt());

            if (contestObject.contains("title") && contestObject["title"].isString())
                shortContest->setTitle(contestObject["title"].toString());

            if (contestObject.contains("isActive") && contestObject["isActive"].isBool())
                shortContest->setIsActive(contestObject["isActive"].toBool());

            if (contestObject.contains("participantsCount") && contestObject["participantsCount"].isDouble())
                shortContest->setCountOfParticipants(contestObject["participantsCount"].toInt());
            ListOfShortContest::instance()->add(shortContest);
        }
    }
    ListOfShortContest::instance()->state->setIsLoading(false);
}

void ListOfShortContest::sendRequest() {
    ListOfShortContest::instance()->state->setIsLoading(true);
//    Requester::instance()->sendRequest("contests", ShortContestController, nullptr);
    Tester test;
    test.sendRequestOnList(ShortContestController);
}
