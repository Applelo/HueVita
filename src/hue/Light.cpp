
#include "Light.hpp"

const stateStruct &Light::getState() const {
    return state;
}

void Light::setState(const stateStruct &state) {
    Light::state = state;
}

const std::string &Light::getType() const {
    return type;
}

void Light::setType(const std::string &type) {
    Light::type = type;
}

const std::string &Light::getName() const {
    return name;
}

void Light::setName(const std::string &name) {
    Light::name = name;
}

const std::string &Light::getModelid() const {
    return modelid;
}

void Light::setModelid(const std::string &modelid) {
    Light::modelid = modelid;
}

const std::string &Light::getSwversion() const {
    return swversion;
}

void Light::setSwversion(const std::string &swversion) {
    Light::swversion = swversion;
}

const std::map<std::string, std::string> &Light::getPointsymbol() const {
    return pointsymbol;
}

void Light::setPointsymbol(const std::map<std::string, std::string> &pointsymbol) {
    Light::pointsymbol = pointsymbol;
}
