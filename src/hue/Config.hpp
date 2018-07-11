
#ifndef HUEVITA_CONFIG_HPP
#define HUEVITA_CONFIG_HPP

#include <string>
#include <map>

struct whitelistItem {
    std::string last_use_date;
    std::string create_date;
    std::string name;
};

struct swupdateStruct {
    int         updatestate;
    std::string url;
    std::string text;
    bool        notify;
};

class Config {
private:
    std::string name;
    std::string mac;
    bool        dhcp;
    std::string ipaddress;
    std::string netmask;
    std::string gateway;
    std::string proxyaddress;
    int         proxyport;
    std::string UTC;
    std::map<std::string, whitelistItem> whitelist;
    std::string swversion;
    swupdateStruct    swudpate;
    bool        linkbutton;
    bool        portalservices;
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getMac() const;

    void setMac(const std::string &mac);

    bool isDhcp() const;

    void setDhcp(bool dhcp);

    const std::string &getIpaddress() const;

    void setIpaddress(const std::string &ipaddress);

    const std::string &getNetmask() const;

    void setNetmask(const std::string &netmask);

    const std::string &getGateway() const;

    void setGateway(const std::string &gateway);

    const std::string &getProxyaddress() const;

    void setProxyaddress(const std::string &proxyaddress);

    int getProxyport() const;

    void setProxyport(int proxyport);

    const std::string &getUTC() const;

    void setUTC(const std::string &UTC);

    const std::map<std::string, whitelistItem> &getWhitelist() const;

    void setWhitelist(const std::map<std::string, whitelistItem> &whitelist);

    const std::string &getSwversion() const;

    void setSwversion(const std::string &swversion);

    const swupdateStruct &getSwudpate() const;

    void setSwudpate(const swupdateStruct &swudpate);

    bool isLinkbutton() const;

    void setLinkbutton(bool linkbutton);

    bool isPortalservices() const;

    void setPortalservices(bool portalservices);
};


#endif //HUEVITA_CONFIG_HPP
