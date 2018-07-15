
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

const std::string &Light::getManufacturername() const {
    return manufacturername;
}

void Light::setManufacturername(const std::string &manufacturername) {
    Light::manufacturername = manufacturername;
}

const std::string &Light::getProductname() const {
    return productname;
}

void Light::setProductname(const std::string &productname) {
    Light::productname = productname;
}

const std::string &Light::getUniqueid() const {
    return uniqueid;
}

void Light::setUniqueid(const std::string &uniqueid) {
    Light::uniqueid = uniqueid;
}

const std::string &Light::getSwversion() const {
    return swversion;
}

void Light::setSwversion(const std::string &swversion) {
    Light::swversion = swversion;
}

const std::string &Light::getSwconfigid() const {
    return swconfigid;
}

void Light::setSwconfigid(const std::string &swconfigid) {
    Light::swconfigid = swconfigid;
}

const std::string &Light::getProductid() const {
    return productid;
}

void Light::setProductid(const std::string &productid) {
    Light::productid = productid;
}
