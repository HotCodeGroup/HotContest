#include <QVariant>
#include "listofshortproblem.h"
#include <QtDebug>

ListOfShortProblem* ListOfShortProblem::p_instance = Q_NULLPTR;

ListOfShortProblem::ListOfShortProblem(QObject *parent) :
    QAbstractListModel(parent)
{
    state = new StateInfo();
}

ListOfShortProblem* ListOfShortProblem::instance() {
    if(!p_instance)
        p_instance = new ListOfShortProblem();
    return p_instance;
}

ListOfShortProblem::~ListOfShortProblem() {
    delete state;
}

int ListOfShortProblem::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

QVariant ListOfShortProblem::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case IdRole:
        return m_data[index.row()]->getId();
    case TitleRole:
        return m_data[index.row()]->getTitle();
    case CompliteRole:
        return m_data[index.row()]->getIsComplite();
    case PointsRole:
        return m_data[index.row()]->getCurPoints();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ListOfShortProblem::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole] = "problemId";
    roles[TitleRole] = "titleStr";
    roles[CompliteRole] = "isComplite";
    roles[PointsRole] = "m_points";

    return roles;
}

StateInfo* ListOfShortProblem::getState() const {
    return state;
}

int ListOfShortProblem::getSize() const {
    return m_data.size();
}

void ListOfShortProblem::add(ShortProblem* problem) {
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(problem);
    endInsertRows();
    emit sizeChanged(m_data.size());
}


void ListOfShortProblem::clear() {
    beginRemoveRows(QModelIndex(), 0, m_data.size() - 1);
    m_data.clear();
    endRemoveRows();
}

void ListOfShortProblem::ShortProblemController(const QJsonObject &obj) {

    if (obj.contains("array_data") && obj["array_data"].isArray()) {
        QJsonArray problemsArray = obj["array_data"].toArray();
        ListOfShortProblem::instance()->clear();

        for (int problemIndex = 0; problemIndex < problemsArray.size(); ++problemIndex) {
            QJsonObject problemObject = problemsArray[problemIndex].toObject();
            auto shortProblem = new ShortProblem();

            shortProblem->setId(problemIndex + 1);

            if (problemObject.contains("title") && problemObject["title"].isString())
                shortProblem->setTitle(problemObject["title"].toString());

            if (problemObject.contains("isDone") && problemObject["isDone"].isBool())
                shortProblem->setIsComplite(problemObject["isDone"].toBool());

            if (problemObject.contains("points") && problemObject["points"].isDouble())
                shortProblem->setCurPoints(problemObject["points"].toInt());
            ListOfShortProblem::instance()->add(shortProblem);
        }
    }
    ListOfShortProblem::instance()->state->setIsLoading(false);
}

void ListOfShortProblem::sendRequest(int contestId) {
    ListOfShortProblem::instance()->state->setIsLoading(true);
//    Requester::instance()->sendRequest("contests/" + QString::number(contestId) + "/problems", ShortProblemController, nullptr);
    Tester test;
    test.sendRequestOnListProblem(ShortProblemController);
}
