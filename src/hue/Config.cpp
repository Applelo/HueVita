
#include "Config.hpp"

Config::Config(json_t *json)  {

    this->name  =   json_string_value(json_object_get(json, "name"));
    this->mac   =   json_string_value(json_object_get(json, "mac"));
    this->dhcp  =   json_boolean_value(json_object_get(json, "dhcp"));
    this->ipaddress = json_string_value(json_object_get(json, "ipaddress"));
    this->netmask = json_string_value(json_object_get(json, "netmask"));
    this->gateway = json_string_value(json_object_get(json, "gateway"));
    this->proxyaddress = json_string_value(json_object_get(json, "proxyaddress"));
    this->proxyport = (int)json_integer_value(json_object_get(json, "gateway"));
    this->UTC = json_string_value(json_object_get(json, "UTC"));

    json_t *whitelist = json_object_get(json, "whitelist");
    const char *key;
    json_t *value;
    whitelistItem item;
    json_object_foreach(whitelist, key, value) {
        item.last_use_date = json_string_value(json_object_get(value, "last use date"));
        item.create_date = json_string_value(json_object_get(value, "create date"));
        item.name = json_string_value(json_object_get(value, "name"));
        this->whitelist.insert(std::pair<std::string,whitelistItem>(key, item));
    }

    this->swversion = json_string_value(json_object_get(json, "swversion"));

    this->swudpate.updatestate = (int) json_integer_value(json_object_get(json_object_get(json, "swupdate"), "updatestate"));
    this->swudpate.url = json_string_value(json_object_get(json_object_get(json, "swupdate"), "url"));
    this->swudpate.text = json_string_value(json_object_get(json_object_get(json, "swupdate"), "text"));
    this->swudpate.notify = json_boolean_value(json_object_get(json_object_get(json, "swupdate"), "notify"));

    this->linkbutton = json_boolean_value(json_object_get(json, "linkbutton"));
    this->portalservices = json_boolean_value(json_object_get(json, "portalservices"));
}

const std::string &Config::getName() const {
    return name;
}

void Config::setName(const std::string &name) {
    Config::name = name;
}

const std::string &Config::getMac() const {
    return mac;
}

void Config::setMac(const std::string &mac) {
    Config::mac = mac;
}

bool Config::isDhcp() const {
    return dhcp;
}

void Config::setDhcp(bool dhcp) {
    Config::dhcp = dhcp;
}

const std::string &Config::getIpaddress() const {
    return ipaddress;
}

void Config::setIpaddress(const std::string &ipaddress) {
    Config::ipaddress = ipaddress;
}

const std::string &Config::getNetmask() const {
    return netmask;
}

void Config::setNetmask(const std::string &netmask) {
    Config::netmask = netmask;
}

const std::string &Config::getGateway() const {
    return gateway;
}

void Config::setGateway(const std::string &gateway) {
    Config::gateway = gateway;
}

const std::string &Config::getProxyaddress() const {
    return proxyaddress;
}

void Config::setProxyaddress(const std::string &proxyaddress) {
    Config::proxyaddress = proxyaddress;
}

int Config::getProxyport() const {
    return proxyport;
}

void Config::setProxyport(int proxyport) {
    Config::proxyport = proxyport;
}

const std::string &Config::getUTC() const {
    return UTC;
}

void Config::setUTC(const std::string &UTC) {
    Config::UTC = UTC;
}

const std::map<std::string, whitelistItem> &Config::getWhitelist() const {
    return whitelist;
}

void Config::setWhitelist(const std::map<std::string, whitelistItem> &whitelist) {
    Config::whitelist = whitelist;
}

const std::string &Config::getSwversion() const {
    return swversion;
}

void Config::setSwversion(const std::string &swversion) {
    Config::swversion = swversion;
}

const swupdateStruct &Config::getSwudpate() const {
    return swudpate;
}

void Config::setSwudpate(const swupdateStruct &swudpate) {
    Config::swudpate = swudpate;
}

bool Config::isLinkbutton() const {
    return linkbutton;
}

void Config::setLinkbutton(bool linkbutton) {
    Config::linkbutton = linkbutton;
}

bool Config::isPortalservices() const {
    return portalservices;
}

void Config::setPortalservices(bool portalservices) {
    Config::portalservices = portalservices;
}

