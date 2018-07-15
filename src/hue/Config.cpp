
#include "Config.hpp"

Config::Config(json_t *json)  {

    this->name  =   json_string_value(json_object_get(json, "name"));
    this->zigbeechannel = (int) json_integer_value(json_object_get(json, "zigbeechannel"));
    this->bridgeid = json_string_value(json_object_get(json, "bridgeid"));
    this->mac   =   json_string_value(json_object_get(json, "mac"));
    this->dhcp  =   json_boolean_value(json_object_get(json, "dhcp"));
    this->ipaddress = json_string_value(json_object_get(json, "ipaddress"));
    this->netmask = json_string_value(json_object_get(json, "netmask"));
    this->gateway = json_string_value(json_object_get(json, "gateway"));
    this->proxyaddress = json_string_value(json_object_get(json, "proxyaddress"));
    this->proxyport = (int)json_integer_value(json_object_get(json, "gateway"));
    this->UTC = json_string_value(json_object_get(json, "UTC"));
    this->localtime = json_string_value(json_object_get(json, "localtime"));
    this->timezone = json_string_value(json_object_get(json, "timezone"));
    this->modelid =  json_string_value(json_object_get(json, "modelid"));
    this->datastoreversion =  json_string_value(json_object_get(json, "datastoreversion"));
    this->swversion = json_string_value(json_object_get(json, "swversion"));
    this->apiversion = json_string_value(json_object_get(json, "apiversion"));

    this->swudpate.updatestate = (int) json_integer_value(json_object_get(json_object_get(json, "swupdate"), "updatestate"));
    this->swudpate.url = json_string_value(json_object_get(json_object_get(json, "swupdate"), "url"));
    this->swudpate.text = json_string_value(json_object_get(json_object_get(json, "swupdate"), "text"));
    this->swudpate.notify = json_boolean_value(json_object_get(json_object_get(json, "swupdate"), "notify"));

    this->swupdate2.checkforupdate = json_boolean_value(json_object_get(json_object_get(json, "swupdate2"), "checkforupdate"));
    this->swupdate2.lastchange = json_string_value(json_object_get(json_object_get(json, "swupdate2"), "lastchange"));
    this->swupdate2.state = json_string_value(json_object_get(json_object_get(json, "swupdate2"), "state"));

    this->linkbutton = json_boolean_value(json_object_get(json, "linkbutton"));
    this->portalservices = json_boolean_value(json_object_get(json, "portalservices"));
    this->portalconnection = json_string_value(json_object_get(json, "portalconnection"));

    this->portalstate.signedon = json_boolean_value(json_object_get(json_object_get(json, "portalstate"), "signedon"));
    this->portalstate.incoming = json_boolean_value(json_object_get(json_object_get(json, "portalstate"), "incoming"));
    this->portalstate.outgoing = json_boolean_value(json_object_get(json_object_get(json, "portalstate"), "outgoing"));
    this->portalstate.communication = json_string_value(json_object_get(json_object_get(json, "portalstate"), "communication"));

    this->internetservices.internet = json_string_value(json_object_get(json_object_get(json, "internetservices"), "internet"));
    this->internetservices.remoteaccess = json_string_value(json_object_get(json_object_get(json, "internetservices"), "remoteaccess"));
    this->internetservices.time = json_string_value(json_object_get(json_object_get(json, "internetservices"), "time"));
    this->internetservices.swupdate = json_string_value(json_object_get(json_object_get(json, "internetservices"), "swupdate"));

    this->factorynew =  json_boolean_value(json_object_get(json, "factorynew"));

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
}

const std::string &Config::getName() const {
    return name;
}

void Config::setName(const std::string &name) {
    Config::name = name;
}

int Config::getZigbeechannel() const {
    return zigbeechannel;
}

void Config::setZigbeechannel(int zigbeechannel) {
    Config::zigbeechannel = zigbeechannel;
}

const std::string &Config::getBridgeid() const {
    return bridgeid;
}

void Config::setBridgeid(const std::string &bridgeid) {
    Config::bridgeid = bridgeid;
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

const std::string &Config::getLocaltime() const {
    return localtime;
}

void Config::setLocaltime(const std::string &localtime) {
    Config::localtime = localtime;
}

const std::string &Config::getTimezone() const {
    return timezone;
}

void Config::setTimezone(const std::string &timezone) {
    Config::timezone = timezone;
}

const std::string &Config::getModelid() const {
    return modelid;
}

void Config::setModelid(const std::string &modelid) {
    Config::modelid = modelid;
}

const std::string &Config::getDatastoreversion() const {
    return datastoreversion;
}

void Config::setDatastoreversion(const std::string &datastoreversion) {
    Config::datastoreversion = datastoreversion;
}

const std::string &Config::getSwversion() const {
    return swversion;
}

void Config::setSwversion(const std::string &swversion) {
    Config::swversion = swversion;
}

const std::string &Config::getApiversion() const {
    return apiversion;
}

void Config::setApiversion(const std::string &apiversion) {
    Config::apiversion = apiversion;
}

const swupdateStruct &Config::getSwudpate() const {
    return swudpate;
}

void Config::setSwudpate(const swupdateStruct &swudpate) {
    Config::swudpate = swudpate;
}

const swupdate2Struct &Config::getSwupdate2() const {
    return swupdate2;
}

void Config::setSwupdate2(const swupdate2Struct &swupdate2) {
    Config::swupdate2 = swupdate2;
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

const std::string &Config::getPortalconnection() const {
    return portalconnection;
}

void Config::setPortalconnection(const std::string &portalconnection) {
    Config::portalconnection = portalconnection;
}

const portalstateStruct &Config::getPortalstate() const {
    return portalstate;
}

void Config::setPortalstate(const portalstateStruct &portalstate) {
    Config::portalstate = portalstate;
}

const internetservicesStruct &Config::getInternetservices() const {
    return internetservices;
}

void Config::setInternetservices(const internetservicesStruct &internetservices) {
    Config::internetservices = internetservices;
}

bool Config::isFactorynew() const {
    return factorynew;
}

void Config::setFactorynew(bool factorynew) {
    Config::factorynew = factorynew;
}

const std::map<std::string, whitelistItem> &Config::getWhitelist() const {
    return whitelist;
}

void Config::setWhitelist(const std::map<std::string, whitelistItem> &whitelist) {
    Config::whitelist = whitelist;
}

