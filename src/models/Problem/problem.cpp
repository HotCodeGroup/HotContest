#include "problem.h"

Problem* Problem::p_instance = Q_NULLPTR;

Problem::Problem(int id,
                 const QString& title,
                 const QString& description,
                 int timeLimit,
                 int memLimit,
                 int triesLeft,
                 int penaltyTry,
                 int penaltyTime,
                 int points) :
id(id),
title(title),
description(description),
timeLimit(timeLimit),
memLimit(memLimit),
triesLeft(triesLeft),
penaltyTry(penaltyTry),
penaltyTime(penaltyTime),
points(points)
{
    state = new StateInfo();
}

Problem* Problem::instance() {
    if(!p_instance)
        p_instance = new Problem();
    return p_instance;
}

Problem::~Problem() {
    delete state;
}

void Problem::ProblemController(const QJsonObject &obj) {
    if (obj.contains("problemId") && obj["problemId"].isDouble())
        Problem::instance()->setId(obj["problemId"].toInt());

    if (obj.contains("title") && obj["title"].isString())
        Problem::instance()->setTitle(obj["title"].toString());

    if (obj.contains("description") && obj["description"].isString())
        Problem::instance()->setDescription(obj["description"].toString());

    if (obj.contains("timeLimit") && obj["timeLimit"].isDouble())
        Problem::instance()->setTimeLimit(obj["timeLimit"].toInt());

    if (obj.contains("memoryLimit") && obj["memoryLimit"].isDouble())
        Problem::instance()->setMemLimit(obj["memoryLimit"].toInt());

    if (obj.contains("triesLeft") && obj["triesLeft"].isDouble())
        Problem::instance()->setTriesLeft(obj["triesLeft"].toInt());

    if (obj.contains("penaltyTry") && obj["penaltyTry"].isDouble())
        Problem::instance()->setPenaltyTry(obj["penaltyTry"].toInt());

    if (obj.contains("penaltyTime") && obj["penaltyTime"].isDouble())
        Problem::instance()->setPenaltyTime(obj["penaltyTime"].toInt());

    if (obj.contains("points") && obj["points"].isDouble())
        Problem::instance()->setPoints(obj["points"].toInt());

    Problem::instance()->state->setIsLoading(false);
}

int Problem::getId() const {
    return id;
}

void Problem::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

const QString& Problem::getTitle() const {
    return title;
}

void Problem::setTitle(const QString& title) {
    this->title = title;
    emit titleChanged(title);
}

const QString& Problem::getDescription() const {
    return description;
}

void Problem::setDescription(const QString& description) {
    this->description = description;
    emit descriptionChanged(description);
}

int Problem::getTimeLimit() const {
    return timeLimit;
}

void Problem::setTimeLimit(int timeLimit) {
    this->timeLimit = timeLimit;
    emit timeLimitChanged(timeLimit);
}

int Problem::getMemLimit() const {
    return memLimit;
}

void Problem::setMemLimit(int memLimit) {
    this->memLimit = memLimit;
    emit memLimitChanged(memLimit);
}

int Problem::getTriesLeft() const {
    return triesLeft;
}

void Problem::setTriesLeft(int triesLeft) {
    this->triesLeft = triesLeft;
    emit triesLeftChanged(triesLeft);
}

int Problem::getPenaltyTry() const {
    return penaltyTry;
}

void Problem::setPenaltyTry(int penaltyTry) {
    this->penaltyTry = penaltyTry;
    emit penaltyTryChanged(penaltyTry);
}

int Problem::getPenaltyTime() const {
    return penaltyTime;
}

void Problem::setPenaltyTime(int penaltyTime) {
    this->penaltyTime = penaltyTime;
    emit penaltyTimeChanged(penaltyTime);
}

int Problem::getPoints() const {
    return points;
}

void Problem::setPoints(int points) {
    this->points = points;
    emit pointsChanged(points);
}

StateInfo* Problem::getState() const {
    return state;
}

void Problem::sendRequest(int contestId, int problemId) {
    Problem::instance()->state->setIsLoading(true);
//    Requester::instance()->sendRequest("contests/" + QString::number(contestId) + "/problems/" + QString::number(problemId), ProblemController, nullptr);
    Tester test;
    test.sendRequestOnProblem(ProblemController);
}
