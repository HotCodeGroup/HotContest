#include <QVariant>
#include "listofsubmit.h"
#include <QtDebug>

ListOfSubmit* ListOfSubmit::p_instance = Q_NULLPTR;

ListOfSubmit::ListOfSubmit(QObject *parent) :
    QAbstractListModel(parent)
{
    state = new StateInfo();
}

ListOfSubmit* ListOfSubmit::instance() {
    if(!p_instance)
        p_instance = new ListOfSubmit();
    return p_instance;
}

ListOfSubmit::~ListOfSubmit() {
    delete state;
}

int ListOfSubmit::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

QVariant ListOfSubmit::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case IdRole:
        return m_data[index.row()]->getId();
    case SubmitTimeRole:
        return m_data[index.row()]->getSubmitTime();
    case ProblemRole:
        return m_data[index.row()]->getProblem();
    case RespCodeRole:
        return m_data[index.row()]->getRespCode();
    case MemoryRole:
        return m_data[index.row()]->getMemory();
    case TimeRole:
        return m_data[index.row()]->getTime();
    case ErrorTestRole:
        return m_data[index.row()]->getErrorTest();
    case PointsRole:
        return m_data[index.row()]->getPoints();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ListOfSubmit::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole] = "submitId";
    roles[SubmitTimeRole] = "submitTime";
    roles[ProblemRole] = "problemId";
    roles[RespCodeRole] = "respCode";
    roles[MemoryRole] = "memoryStr";
    roles[TimeRole] = "timeStr";
    roles[ErrorTestRole] = "errorTest";
    roles[PointsRole] = "curPoints";

    return roles;
}

StateInfo* ListOfSubmit::getState() const {
    return state;
}

int ListOfSubmit::getSize() const {
    return m_data.size();
}

void ListOfSubmit::add(Submit* submit) {
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(submit);
    endInsertRows();
    emit sizeChanged(m_data.size());
}

void ListOfSubmit::clear() {
    beginRemoveRows(QModelIndex(), 0, m_data.size() - 1);
    m_data.clear();
    endRemoveRows();
}

void ListOfSubmit::SubmitsController(const QJsonObject &obj) {
    if (obj.contains("array_data") && obj["array_data"].isArray()) {
        QJsonArray submitsArray = obj["array_data"].toArray();
        ListOfSubmit::instance()->clear();

        for (int submitIndex = 0; submitIndex < submitsArray.size(); ++submitIndex) {
            QJsonObject submitObject = submitsArray[submitIndex].toObject();
            auto submit = new Submit();

            if (submitObject.contains("submitId") && submitObject["submitId"].isDouble())
                submit->setId(submitObject["submitId"].toInt());

            if (submitObject.contains("sendTime") && submitObject["sendTime"].isString()) {
                submit->setDTSubmitTime(QDateTime::fromString(submitObject["sendTime"].toString(), "yyyy-MM-ddTHH:mm:ss"));
                submit->setSubmitTime(submit->getDTSubmitTime().toString("dd MMM yyyy, HH:mm:ss"));
            }

            if (submitObject.contains("result") && submitObject["result"].isDouble())
                submit->setRespCode(submitObject["result"].toInt());

            if (submitObject.contains("problemId") && submitObject["problemId"].isDouble())
                submit->setProblem(submitObject["problemId"].toInt());

            if (submitObject.contains("time") && submitObject["time"].isDouble())
                submit->setTime(submitObject["time"].toInt());

            if (submitObject.contains("memory") && submitObject["memory"].isDouble())
                submit->setMemory(submitObject["memory"].toInt());

            if (submitObject.contains("testError") && submitObject["testError"].isDouble())
                submit->setErrorTest(submitObject["testError"].toInt());

            if (submitObject.contains("points") && submitObject["points"].isDouble())
                submit->setPoints(submitObject["points"].toInt());

            ListOfSubmit::instance()->add(submit);
        }
    }
    ListOfSubmit::instance()->state->setIsLoading(false);
}

void ListOfSubmit::sendShortRequest(int contestId, int problemId) {
    ListOfSubmit::instance()->state->setIsLoading(true);
//    Requester::instance()->sendRequest("contests/" + QString::number(contestId) + "/reports?problem=" + QString::number(problemId), SubmitsController, nullptr);
    Tester test;
    test.sendRequestOnListSubmitShort(SubmitsController);
}

void ListOfSubmit::sendRequest(int contestId) {
    ListOfSubmit::instance()->state->setIsLoading(true);
//    Requester::instance()->sendRequest("contests/" + QString::number(contestId) + "/reports/", SubmitsController, nullptr);
    Tester test;
    test.sendRequestOnListSubmit(SubmitsController);
}
