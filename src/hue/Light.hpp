
#ifndef HUEVITA_LIGHT_HPP
#define HUEVITA_LIGHT_HPP

#include <string>
#include <map>

struct stateStruct {
    bool on;
    int bri;
    int sat;
    int *xy;
    int ct;
    std::string alert;
    std::string effect;
    std::string colormode;
    bool reachable;
};

class Light {
    private:
        stateStruct state;
        std::string type;
        std::string name;
        std::string modelid;
        std::string swversion;
        std::map<std::string,std::string> pointsymbol;
    public:
        const stateStruct &getState() const;

        void setState(const stateStruct &state);

        const std::string &getType() const;

        void setType(const std::string &type);

        const std::string &getName() const;

        void setName(const std::string &name);

        const std::string &getModelid() const;

        void setModelid(const std::string &modelid);

        const std::string &getSwversion() const;

        void setSwversion(const std::string &swversion);

        const std::map<std::string, std::string> &getPointsymbol() const;

        void setPointsymbol(const std::map<std::string, std::string> &pointsymbol);

};


#endif //HUEVITA_LIGHT_HPP
