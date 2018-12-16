#include "stateinfo.h"
#include <QDebug>

StateInfo::StateInfo(bool isLoading) :
isLoading(isLoading)
{}

StateInfo::~StateInfo() {

}

bool StateInfo::getIsLoading() const {
    return isLoading;
}

void StateInfo::setIsLoading(bool isLoading) {
    this->isLoading = isLoading;
    emit isLoadingChanged(isLoading);
}
