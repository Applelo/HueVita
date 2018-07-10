
#ifndef HUEVITA_NET_HPP
#define HUEVITA_NET_HPP

#include <psp2/sysmodule.h>
#include <psp2/net/net.h>
#include <psp2/net/netctl.h>
#include <psp2/net/http.h>
#include <curl/curl.h>
#include <malloc.h>


class Net {
public:
    void init();
    void terminate();
};


#endif //HUEVITA_NET_HPP
