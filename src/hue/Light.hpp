
#ifndef HUEVITA_LIGHT_HPP
#define HUEVITA_LIGHT_HPP

#include <string>
#include <map>
#include <jansson.h>

struct stateStruct {
    bool on;
    int bri;
    int sat;
    int *xy;
    int ct;
    std::string alert;
    std::string effect;
    std::string colormode;
    std::string mode;
    bool reachable;
};

struct capabilitiesStruct {
    bool certified;
    std::map<std::string, int> control;
    std::map<std::string, bool> streaming;
};

struct configStruct {
    std::string archetype;
    std::string function;
    std::string direction;
};

class Light {
    private:
        stateStruct state;
        std::string type;
        std::string name;
        std::string modelid;
        std::string manufacturername;
        std::string productname;
        capabilitiesStruct capabilities;
        configStruct config;
        std::string uniqueid;
        std::string swversion;
        std::string swconfigid;
        std::string productid;

    public:
        Light(json_t *json);

    const stateStruct &getState() const;

    void setState(const stateStruct &state);

    const std::string &getType() const;

    void setType(const std::string &type);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getModelid() const;

    void setModelid(const std::string &modelid);

    const std::string &getManufacturername() const;

    void setManufacturername(const std::string &manufacturername);

    const std::string &getProductname() const;

    void setProductname(const std::string &productname);

    const capabilitiesStruct &getCapabilities() const;

    void setCapabilities(const capabilitiesStruct &capabilities);

    const configStruct &getConfig() const;

    void setConfig(const configStruct &config);

    const std::string &getUniqueid() const;

    void setUniqueid(const std::string &uniqueid);

    const std::string &getSwversion() const;

    void setSwversion(const std::string &swversion);

    const std::string &getSwconfigid() const;

    void setSwconfigid(const std::string &swconfigid);

    const std::string &getProductid() const;

    void setProductid(const std::string &productid);

};


#endif //HUEVITA_LIGHT_HPP
