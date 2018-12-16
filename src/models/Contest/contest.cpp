#include "contest.h"
#include <QThread>

Contest* Contest::p_instance = Q_NULLPTR;

Contest::Contest(int id,
                 const QString& title,
                 const QString& description,
                 bool isPrivate) :
id(id),
title(title),
description(description),
startTime(),
finishTime(),
isPrivate(isPrivate)
{
    state = new StateInfo();
}

Contest* Contest::instance() {
    if(!p_instance)
        p_instance = new Contest();
    return p_instance;
}

Contest::~Contest() {
    delete state;
}

void Contest::ContestController(const QJsonObject &obj) {
    if (obj.contains("contestId") && obj["contestId"].isDouble())
        Contest::instance()->setId(obj["contestId"].toInt());

    if (obj.contains("title") && obj["title"].isString())
        Contest::instance()->setTitle(obj["title"].toString());

    if (obj.contains("description") && obj["description"].isString())
        Contest::instance()->setDescription(obj["description"].toString());

    if (obj.contains("startTime") && obj["startTime"].isString()) {
        Contest::instance()->setDTStartTime(QDateTime::fromString(obj["startTime"].toString(), "yyyy-MM-ddTHH:mm:ss"));
        Contest::instance()->setStartTime(Contest::instance()->getDTStartTime().toString("dd MMM yyyy, HH:mm:ss"));
    }

    if (obj.contains("finishTime") && obj["finishTime"].isString()) {
        Contest::instance()->setDTFinishTime(QDateTime::fromString(obj["finishTime"].toString(), "yyyy-MM-ddTHH:mm:ss"));
        Contest::instance()->setFinishTime(Contest::instance()->getDTFinishTime().toString("dd MMM yyyy, HH:mm:ss"));
    }
    Contest::instance()->state->setIsLoading(false);
}

int Contest::getId() const {
    return id;
}

void Contest::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

const QString& Contest::getTitle() const {
    return title;
}

void Contest::setTitle(const QString& title) {
    this->title = title;
    emit titleChanged(title);
}

const QString& Contest::getDescription() const {
    return description;
}

void Contest::setDescription(const QString& description) {
    this->description = description;
    emit descriptionChanged(description);
}

const QString& Contest::getStartTime() const {
    return startTime;
}

void Contest::setStartTime(const QString& startTime) {
    this->startTime = startTime;
    emit startTimeChanged(startTime);
}

const QString& Contest::getFinishTime() const {
    return finishTime;
}

void Contest::setFinishTime(const QString& finishTime) {
    this->finishTime = finishTime;
    emit finishTimeChanged(finishTime);
}

bool Contest::getIsPrivate() const {
    return isPrivate;
}

void Contest::setIsPrivate(bool value) {
    this->isPrivate = value;
    emit isPrivateChanged(value);
}

const QDateTime& Contest::getDTStartTime() const {
    return DTstartTime;
}

void Contest::setDTStartTime(const QDateTime& startTime) {
    this->DTstartTime = startTime;
}

const QDateTime& Contest::getDTFinishTime() const {
    return DTfinishTime;
}

void Contest::setDTFinishTime(const QDateTime& finishTime) {
    this->DTfinishTime = finishTime;
}

StateInfo* Contest::getState() const {
    return state;
}

void Contest::sendRequest(int contestId) {
    Contest::instance()->state->setIsLoading(true);
//    Requester::instance()->sendRequest("contests/" + QString::number(contestId), ContestController, nullptr);
    Tester test;
    test.sendRequestOnContest(ContestController);
}
