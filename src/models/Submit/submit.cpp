#include "submit.h"

Submit::Submit(int id,
                 const QString& submitTime,
                 int problem,
                 int respCode,
                 int memory,
                 int time,
                 int errorTest,
                 int points) :
id(id),
submitTime(submitTime),
problem(problem),
respCode(respCode),
memory(memory),
time(time),
errorTest(errorTest),
points(points)
{}

Submit::~Submit() {

}

int Submit::getId() const {
    return id;
}

void Submit::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

const QString& Submit::getSubmitTime() const {
    return submitTime;
}

void Submit::setSubmitTime(const QString& submitTime) {
    this->submitTime = submitTime;
    emit submitTimeChanged(submitTime);
}

int Submit::getProblem() const {
    return problem;
}

void Submit::setProblem(int problem) {
    this->problem = problem;
    emit problemChanged(problem);
}

int Submit::getRespCode() const {
    return respCode;
}

void Submit::setRespCode(int respCode) {
    this->respCode = respCode;
    emit respCodeChanged(respCode);
}

int Submit::getMemory() const {
    return memory;
}

void Submit::setMemory(int memory) {
    this->memory = memory;
    emit memoryChanged(memory);
}

int Submit::getTime() const {
    return time;
}

void Submit::setTime(int time) {
    this->time = time;
    emit timeChanged(time);
}

int Submit::getErrorTest() const {
    return errorTest;
}

void Submit::setErrorTest(int errorTest) {
    this->errorTest = errorTest;
    emit errorTestChanged(errorTest);
}

int Submit::getPoints() const {
    return points;
}

void Submit::setPoints(int points) {
    this->points = points;
    emit pointsChanged(points);
}

const QDateTime& Submit::getDTSubmitTime() const {
    return DTsubmitTime;
}

void Submit::setDTSubmitTime(const QDateTime& DTsubmitTime) {
    this->DTsubmitTime = DTsubmitTime;
}
