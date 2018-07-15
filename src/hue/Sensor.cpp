
#include "Sensor.hpp"

Sensor::Sensor(json_t *json) {
    this->config.on = json_boolean_value(json_object_get(json_object_get(json, "config"), "on"));
    this->config.configured = json_boolean_value(json_object_get(json_object_get(json, "config"), "configured"));
    this->config.sunriseoffset = (int) json_integer_value(json_object_get(json_object_get(json, "config"), "sunreiseoffeset"));
    this->config.sunsetoffeset = (int) json_integer_value(json_object_get(json_object_get(json, "config"), "sunsetoffeset"));

    this->name = json_string_value(json_object_get(json, "name"));
    this->type = json_string_value(json_object_get(json, "type"));
    this->modelid = json_string_value(json_object_get(json, "modelid"));
    this->manufacturername = json_string_value(json_object_get(json, "manufacturername"));
    this->swversion = json_string_value(json_object_get(json, "swversion"));
}

const configStruct &Sensor::getConfig() const {
    return config;
}

void Sensor::setConfig(const configStruct &config) {
    Sensor::config = config;
}

const std::string &Sensor::getName() const {
    return name;
}

void Sensor::setName(const std::string &name) {
    Sensor::name = name;
}

const std::string &Sensor::getType() const {
    return type;
}

void Sensor::setType(const std::string &type) {
    Sensor::type = type;
}

const std::string &Sensor::getModelid() const {
    return modelid;
}

void Sensor::setModelid(const std::string &modelid) {
    Sensor::modelid = modelid;
}

const std::string &Sensor::getManufacturername() const {
    return manufacturername;
}

void Sensor::setManufacturername(const std::string &manufacturername) {
    Sensor::manufacturername = manufacturername;
}

const std::string &Sensor::getSwversion() const {
    return swversion;
}

void Sensor::setSwversion(const std::string &swversion) {
    Sensor::swversion = swversion;
}
