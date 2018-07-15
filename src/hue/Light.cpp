
#include "Light.hpp"

Light::Light(json_t *json)  {

    this->state.on = json_boolean_value(json_object_get(json_object_get(json, "state"), "on"));
    this->state.bri = (int) json_integer_value(json_object_get(json_object_get(json, "state"), "bri"));
    for (int i = 0; i < 2; ++i) {
        this->state.xy[i] = (int) json_integer_value(json_array_get(json_object_get(json_object_get(json, "state"), "xy"), (size_t) i));
    }
    this->state.alert = json_string_value(json_object_get(json_object_get(json, "state"), "alert"));
    this->state.mode = json_string_value(json_object_get(json_object_get(json, "state"), "mode"));
    this->state.reachable = json_boolean_value(json_object_get(json_object_get(json, "state"), "reachable"));

    this->type = json_string_value(json_object_get(json, "type"));
    this->name  =   json_string_value(json_object_get(json, "name"));
    this->modelid =  json_string_value(json_object_get(json, "modelid"));
    this->manufacturername =  json_string_value(json_object_get(json, "manufacturername"));
    this->productname = json_string_value(json_object_get(json, "productname"));

    json_t *control = json_object_get(json_object_get(json, "capabilities"), "control");
    json_t *streaming = json_object_get(json_object_get(json, "capabilities"), "streaming");
    const char *key;
    json_t *value;
    this->capabilities.certified = json_boolean_value(json_object_get(json_object_get(json, "capabilities"), "certified"));
    json_object_foreach(control, key, value) {
        this->capabilities.control.insert(std::pair<std::string,int>(key, (int) json_integer_value(value)));
    }
    json_object_foreach(streaming, key, value) {
        this->capabilities.streaming.insert(std::pair<std::string,bool>(key, json_boolean_value(value)));
    }

    this->config.archetype = json_string_value(json_object_get(json_object_get(json, "config"), "archetype"));
    this->config.function = json_string_value(json_object_get(json_object_get(json, "config"), "function"));
    this->config.direction = json_string_value(json_object_get(json_object_get(json, "config"), "direction"));

    this->uniqueid = json_string_value(json_object_get(json, "uniqueid"));
    this->swversion = json_string_value(json_object_get(json, "swversion"));
    this->swconfigid = json_string_value(json_object_get(json, "swconfigid"));
    this->productid = json_string_value(json_object_get(json, "productid"));

}

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

const capabilitiesStruct &Light::getCapabilities() const {
    return capabilities;
}

void Light::setCapabilities(const capabilitiesStruct &capabilities) {
    Light::capabilities = capabilities;
}

const configStruct &Light::getConfig() const {
    return config;
}

void Light::setConfig(const configStruct &config) {
    Light::config = config;
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

