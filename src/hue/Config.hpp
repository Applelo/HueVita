
#ifndef HUEVITA_CONFIG_HPP
#define HUEVITA_CONFIG_HPP

#include <string>
#include <map>
#include <jansson.h>

struct whitelistItem {
    std::string last_use_date;
    std::string create_date;
    std::string name;
};

struct swupdateStruct {
    int         updatestate;
    bool        checkforupdate;
    std::string url;
    std::string text;
    bool        notify;
};

struct swupdate2Struct {
    bool checkforupdate;
    std::string lastchange;
    std::string state;
};

struct portalstateStruct {
    bool        signedon;
    bool        incoming;
    bool        outgoing;
    std::string communication;
};

struct internetservicesStruct {
    std::string internet;
    std::string remoteaccess;
    std::string time;
    std::string swupdate;
};


class Config {
private:
    std::string     name;
    int             zigbeechannel;
    std::string     bridgeid;
    std::string     mac;
    bool            dhcp;
    std::string     ipaddress;
    std::string     netmask;
    std::string     gateway;
    std::string     proxyaddress;
    int             proxyport;
    std::string     UTC;
    std::string     localtime;
    std::string     timezone;
    std::string     modelid;
    std::string     datastoreversion;
    std::string     swversion;
    std::string     apiversion;
    swupdateStruct  swudpate;
    swupdate2Struct swupdate2;
    bool            linkbutton;
    bool            portalservices;
    std::string     portalconnection;
    portalstateStruct       portalstate;
    internetservicesStruct  internetservices;
    bool            factorynew;
    std::map<std::string, whitelistItem> whitelist;
public:
    Config(json_t *json);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getZigbeechannel() const;

    void setZigbeechannel(int zigbeechannel);

    const std::string &getBridgeid() const;

    void setBridgeid(const std::string &bridgeid);

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

    const std::string &getLocaltime() const;

    void setLocaltime(const std::string &localtime);

    const std::string &getTimezone() const;

    void setTimezone(const std::string &timezone);

    const std::string &getModelid() const;

    void setModelid(const std::string &modelid);

    const std::string &getDatastoreversion() const;

    void setDatastoreversion(const std::string &datastoreversion);

    const std::string &getSwversion() const;

    void setSwversion(const std::string &swversion);

    const std::string &getApiversion() const;

    void setApiversion(const std::string &apiversion);

    const swupdateStruct &getSwudpate() const;

    void setSwudpate(const swupdateStruct &swudpate);

    const swupdate2Struct &getSwupdate2() const;

    void setSwupdate2(const swupdate2Struct &swupdate2);

    bool isLinkbutton() const;

    void setLinkbutton(bool linkbutton);

    bool isPortalservices() const;

    void setPortalservices(bool portalservices);

    const std::string &getPortalconnection() const;

    void setPortalconnection(const std::string &portalconnection);

    const portalstateStruct &getPortalstate() const;

    void setPortalstate(const portalstateStruct &portalstate);

    const internetservicesStruct &getInternetservices() const;

    void setInternetservices(const internetservicesStruct &internetservices);

    bool isFactorynew() const;

    void setFactorynew(bool factorynew);

    const std::map<std::string, whitelistItem> &getWhitelist() const;

    void setWhitelist(const std::map<std::string, whitelistItem> &whitelist);

};


#endif //HUEVITA_CONFIG_HPP
