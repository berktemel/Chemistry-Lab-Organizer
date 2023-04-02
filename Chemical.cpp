//
// Berk Temel 22002675
//

#include "Chemical.h"

Chemical::Chemical(int id, string type, int cabId) {
    this->id = id;
    this->type = type;
    this->cabId = cabId;
}

Chemical::Chemical() {
    id = 0;
}

int Chemical::getId() const {
    return id;
}

int Chemical::getCabinetId() const {
    return cabId;
}

void Chemical::setId(int id) {
    this->id = id;
}

void Chemical::setType(string type) {
    this->type = type;
}

string Chemical::getChemicalType() const {
    return type;
}

bool Chemical::chemicalExists() const{
    return id != 0;
}