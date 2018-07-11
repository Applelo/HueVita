
#include "Config.hpp"

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
