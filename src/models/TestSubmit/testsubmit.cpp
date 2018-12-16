#include "testsubmit.h"

TestSubmit::TestSubmit(int id,
                 int verdict,
                 int memory,
                 int time) :
id(id),
verdict(verdict),
memory(memory),
time(time)
{}

TestSubmit::~TestSubmit() {

}

int TestSubmit::getId() const {
    return id;
}

void TestSubmit::setId(int id) {
    this->id = id;
    emit idChanged(id);
}

int TestSubmit::getVerdict() const {
    return verdict;
}

void TestSubmit::setVerdict(int verdict) {
    this->verdict = verdict;
    emit verdictChanged(verdict);
}

int TestSubmit::getMemory() const {
    return memory;
}

void TestSubmit::setMemory(int memory) {
    this->memory = memory;
    emit memoryChanged(memory);
}

int TestSubmit::getTime() const {
    return time;
}

void TestSubmit::setTime(int time) {
    this->time = time;
    emit timeChanged(time);
}
