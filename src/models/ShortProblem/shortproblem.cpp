#include "shortproblem.h"

ShortProblem::ShortProblem(int id,
                           const QString& title,
                           int curPoints,
                           bool isComplite) :
id(id),
title(title),
curPoints(curPoints),
isComplite(isComplite)
{}

ShortProblem::~ShortProblem() {

}

int ShortProblem::getId() const {
    return id;
}

void ShortProblem::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

const QString& ShortProblem::getTitle() const {
    return title;
}

void ShortProblem::setTitle(const QString& title) {
    this->title = title;
    emit titleChanged(title);
}

int ShortProblem::getCurPoints() const {
    return curPoints;
}

void ShortProblem::setCurPoints(int curPoints) {
    this->curPoints = curPoints;
    emit curPointsChanged(curPoints);
}

bool ShortProblem::getIsComplite() const {
    return isComplite;
}
void ShortProblem::setIsComplite(bool isComplite) {
    this->isComplite = isComplite;
    emit isCompliteChanged(isComplite);
}
