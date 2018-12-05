#include <QVariant>
#include "listoftestsubmit.h"
#include <QtDebug>

ListOfTestSubmit* ListOfTestSubmit::p_instance = Q_NULLPTR;

ListOfTestSubmit::ListOfTestSubmit(QObject *parent) :
    QAbstractListModel(parent)
{
    state = new StateInfo();
}

ListOfTestSubmit* ListOfTestSubmit::instance() {
    if(!p_instance)
        p_instance = new ListOfTestSubmit();
    return p_instance;
}

ListOfTestSubmit::~ListOfTestSubmit() {
    delete state;
}

int ListOfTestSubmit::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

QVariant ListOfTestSubmit::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case IdRole:
        return m_data[index.row()]->getId();
    case VerdictRole:
        return m_data[index.row()]->getVerdict();
    case MemoryRole:
        return m_data[index.row()]->getMemory();
    case TimeRole:
        return m_data[index.row()]->getTime();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ListOfTestSubmit::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole] = "testSubmitId";
    roles[VerdictRole] = "testVerdict";
    roles[MemoryRole] = "memoryStr";
    roles[TimeRole] = "timeStr";

    return roles;
}

StateInfo* ListOfTestSubmit::getState() const {
    return state;
}

int ListOfTestSubmit::getSize() const {
    return m_data.size();
}

void ListOfTestSubmit::add(TestSubmit* testSubmit) {
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(testSubmit);
    endInsertRows();
    emit sizeChanged(m_data.size());
}

void ListOfTestSubmit::clear() {
    beginRemoveRows(QModelIndex(), 0, m_data.size() - 1);
    m_data.clear();
    endRemoveRows();
}

void ListOfTestSubmit::TestSubmitsController(const QJsonObject &obj) {
    if (obj.contains("array_data") && obj["array_data"].isArray()) {
        QJsonArray testSubmitsArray = obj["array_data"].toArray();
        ListOfTestSubmit::instance()->clear();

        for (int testSubmitIndex = 0; testSubmitIndex < testSubmitsArray.size(); ++testSubmitIndex) {
            QJsonObject testSubmitObject = testSubmitsArray[testSubmitIndex].toObject();
            auto testSubmit = new TestSubmit();

            testSubmit->setId(testSubmitIndex + 1);

            if (testSubmitObject.contains("result") && testSubmitObject["result"].isDouble())
                testSubmit->setVerdict(testSubmitObject["result"].toInt());

            if (testSubmitObject.contains("time") && testSubmitObject["time"].isDouble())
                testSubmit->setTime(testSubmitObject["time"].toInt());

            if (testSubmitObject.contains("memory") && testSubmitObject["memory"].isDouble())
                testSubmit->setMemory(testSubmitObject["memory"].toInt());

            ListOfTestSubmit::instance()->add(testSubmit);
        }
    }
    ListOfTestSubmit::instance()->state->setIsLoading(false);
}

void ListOfTestSubmit::sendRequest(int contestId, int submitId) {
    ListOfTestSubmit::instance()->state->setIsLoading(true);
    Requester::instance()->sendRequest("contests/" + QString::number(contestId) + "/reports/" + QString::number(submitId), TestSubmitsController, nullptr);
//    Tester test;
//    test.sendRequestOnListTestSubmit(TestSubmitsController);
}
