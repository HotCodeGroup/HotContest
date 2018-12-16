#include "participant.h"

Participant::Participant(int id, const QString& username) :
id(id),
username(username)
{}

Participant::~Participant() {

}

int Participant::getId() const {
    return id;
}

void Participant::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

const QString& Participant::getUsername() const {
    return username;
}

void Participant::setUsername(const QString& username) {
    this->username = username;
    emit usernameChanged(username);
}
