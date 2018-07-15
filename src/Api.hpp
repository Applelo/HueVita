//
// Created by bouba on 10/07/2018.
//

#ifndef HUEVITA_API_HPP
#define HUEVITA_API_HPP

#include <curl/curl.h>
#include <jansson.h>

#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class Api {
private:
    CURL *curl;
    CURLcode curlResult;
    std::string username;
    std::string ipAddress;
public:
    //methods

    int createUsername();

    //getter
    const std::string &getUsername() const;
    const std::string &getIpAddress() const;
    std::string getApiAddress();

    //setter
    void setUsername(const std::string &username);
    void setIpAddress(const std::string &ipAddress);

};


#endif //HUEVITA_API_HPP
