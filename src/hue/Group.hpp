
#ifndef HUEVITA_GROUP_HPP
#define HUEVITA_GROUP_HPP


#include <string>
#include <vector>
#include <jansson.h>

struct stateStruct {
    bool all_on;
    bool any_on;
};

struct actionStruct {
    bool on;
    int bri;
    std::string alert;
};

class Group {
    private:
        std::string name;
        std::vector <std::string> lights;
        std::string type;
        stateStruct state;
        bool recycle;
        std::string classL;//can't named class because oop language :'(
        actionStruct action;
    public:
    Group(json_t *json);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<std::string> &getLights() const;

    void setLights(const std::vector<std::string> &lights);

    const std::string &getType() const;

    void setType(const std::string &type);

    const stateStruct &getState() const;

    void setState(const stateStruct &state);

    bool isRecycle() const;

    void setRecycle(bool recycle);

    const std::string &getClassL() const;

    void setClassL(const std::string &classL);

    const actionStruct &getAction() const;

    void setAction(const actionStruct &action);
};


#endif //HUEVITA_GROUP_HPP
