
#include "Group.hpp"

Group::Group(json_t *json) {
    this->name  =   json_string_value(json_object_get(json, "name"));

    json_t *lights = json_object_get(json, "lights");
    size_t index;
    json_t *value;
    json_array_foreach(lights, index, value) {
        this->lights.emplace_back(json_string_value(value));
    }

    this->type = json_string_value(json_object_get(json, "type"));

    this->state.all_on = json_boolean_value(json_object_get(json_object_get(json, "state"), "all_on"));
    this->state.any_on = json_boolean_value(json_object_get(json_object_get(json, "state"), "any_on"));

    this->recycle = json_boolean_value(json_object_get(json, "recycle"));
    this->classL = json_string_value(json_object_get(json, "class"));

    this->action.on = json_boolean_value(json_object_get(json_object_get(json, "action"), "on"));
    this->action.bri = (int) json_integer_value(json_object_get(json_object_get(json, "action"), "bri"));
    this->action.alert = json_string_value(json_object_get(json_object_get(json, "action"), "alert"));
}

const std::string &Group::getName() const {
    return name;
}

void Group::setName(const std::string &name) {
    Group::name = name;
}

const std::vector<std::string> &Group::getLights() const {
    return lights;
}

void Group::setLights(const std::vector<std::string> &lights) {
    Group::lights = lights;
}

const std::string &Group::getType() const {
    return type;
}

void Group::setType(const std::string &type) {
    Group::type = type;
}

const stateStruct &Group::getState() const {
    return state;
}

void Group::setState(const stateStruct &state) {
    Group::state = state;
}

bool Group::isRecycle() const {
    return recycle;
}

void Group::setRecycle(bool recycle) {
    Group::recycle = recycle;
}

const std::string &Group::getClassL() const {
    return classL;
}

void Group::setClassL(const std::string &classL) {
    Group::classL = classL;
}

const actionStruct &Group::getAction() const {
    return action;
}

void Group::setAction(const actionStruct &action) {
    Group::action = action;
}
