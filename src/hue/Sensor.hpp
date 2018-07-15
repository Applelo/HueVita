
#ifndef HUEVITA_SENSOR_HPP
#define HUEVITA_SENSOR_HPP

#include <string>
#include <jansson.h>

struct configStruct {
    bool on;
    bool configured;
    int sunriseoffset;
    int sunsetoffeset;
};

class Sensor {
    private:
        configStruct config;
        std::string name;
        std::string type;
        std::string modelid;
        std::string manufacturername;
        std::string swversion;
    public:
        Sensor(json_t *json);

    const configStruct &getConfig() const;

    void setConfig(const configStruct &config);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getType() const;

    void setType(const std::string &type);

    const std::string &getModelid() const;

    void setModelid(const std::string &modelid);

    const std::string &getManufacturername() const;

    void setManufacturername(const std::string &manufacturername);

    const std::string &getSwversion() const;

    void setSwversion(const std::string &swversion);
};


#endif //HUEVITA_SENSOR_HPP
