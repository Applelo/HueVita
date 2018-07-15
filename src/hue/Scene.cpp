//
// Created by bouba on 15/07/2018.
//

#include "Scene.hpp"

Scene::Scene(json_t *json) {
    this->name  =   json_string_value(json_object_get(json, "name"));

    json_t *lights = json_object_get(json, "lights");
    size_t index;
    json_t *value;
    json_array_foreach(lights, index, value) {
        this->lights.emplace_back(json_string_value(value));
    }

    this->owner  =   json_string_value(json_object_get(json, "owner"));
    this->recycle  =   json_boolean_value(json_object_get(json, "recycle"));
    this->locked  =   json_boolean_value(json_object_get(json, "locked"));

    this->appdata.version = (int) json_integer_value(json_object_get(json_object_get(json, "appdata"), "version"));
    this->appdata.data = json_string_value(json_object_get(json_object_get(json, "appdata"), "data"));

    this->picture = json_string_value(json_object_get(json, "picture"));
    this->lastupdated = json_string_value(json_object_get(json, "lastupdated"));
    this->version = json_string_value(json_object_get(json, "version"));

}

const std::string &Scene::getName() const {
    return name;
}

void Scene::setName(const std::string &name) {
    Scene::name = name;
}

const std::vector<std::string> &Scene::getLights() const {
    return lights;
}

void Scene::setLights(const std::vector<std::string> &lights) {
    Scene::lights = lights;
}

const std::string &Scene::getOwner() const {
    return owner;
}

void Scene::setOwner(const std::string &owner) {
    Scene::owner = owner;
}

bool Scene::isRecycle() const {
    return recycle;
}

void Scene::setRecycle(bool recycle) {
    Scene::recycle = recycle;
}

bool Scene::isLocked() const {
    return locked;
}

void Scene::setLocked(bool locked) {
    Scene::locked = locked;
}

const appdataStruct &Scene::getAppdata() const {
    return appdata;
}

void Scene::setAppdata(const appdataStruct &appdata) {
    Scene::appdata = appdata;
}

const std::string &Scene::getPicture() const {
    return picture;
}

void Scene::setPicture(const std::string &picture) {
    Scene::picture = picture;
}

const std::string &Scene::getLastupdated() const {
    return lastupdated;
}

void Scene::setLastupdated(const std::string &lastupdated) {
    Scene::lastupdated = lastupdated;
}

const std::string &Scene::getVersion() const {
    return version;
}

void Scene::setVersion(const std::string &version) {
    Scene::version = version;
}
