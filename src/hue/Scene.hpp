//
// Created by bouba on 15/07/2018.
//

#ifndef HUEVITA_SCENE_HPP
#define HUEVITA_SCENE_HPP


#include <string>
#include <vector>
#include <jansson.h>

struct appdataStruct {
    int version;
    std::string data;
};

class Scene {
    private:
        std::string name;
        std::vector<std::string> lights;
        std::string owner;
        bool recycle;
        bool locked;
        appdataStruct appdata;
        std::string picture;
        std::string lastupdated;
        std::string version;
    public:
        Scene(json_t *json);

        const std::string &getName() const;

        void setName(const std::string &name);

        const std::vector<std::string> &getLights() const;

        void setLights(const std::vector<std::string> &lights);

        const std::string &getOwner() const;

        void setOwner(const std::string &owner);

        bool isRecycle() const;

        void setRecycle(bool recycle);

        bool isLocked() const;

        void setLocked(bool locked);

        const appdataStruct &getAppdata() const;

        void setAppdata(const appdataStruct &appdata);

        const std::string &getPicture() const;

        void setPicture(const std::string &picture);

        const std::string &getLastupdated() const;

        void setLastupdated(const std::string &lastupdated);

        const std::string &getVersion() const;

        void setVersion(const std::string &version);
};


#endif //HUEVITA_SCENE_HPP
