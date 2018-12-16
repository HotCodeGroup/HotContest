#include "shortcontest.h"

ShortContest::ShortContest(int id, const QString& title,
                           int countOfParticipants, bool isActive) :
id(id),
title(title),
countOfParticipants(countOfParticipants),
isActive(isActive)
{}

ShortContest::~ShortContest() {

}

int ShortContest::getId() const {
    return id;
}

void ShortContest::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

const QString& ShortContest::getTitle() const {
    return title;
}

void ShortContest::setTitle(const QString& title) {
    this->title = title;
    emit titleChanged(title);
}

int ShortContest::getCountOfParticipants() const {
    return countOfParticipants;
}

void ShortContest::setCountOfParticipants(int countOfParticipants) {
    this->countOfParticipants = countOfParticipants;
    emit countOfParticipantsChanged(countOfParticipants);
}

bool ShortContest::getIsActive() const {
    return isActive;
}
void ShortContest::setIsActive(bool isActive) {
    this->isActive = isActive;
    emit isActiveChanged(isActive);
}
