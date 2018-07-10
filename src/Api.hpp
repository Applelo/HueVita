//
// Created by bouba on 10/07/2018.
//

#ifndef HUEVITA_API_HPP
#define HUEVITA_API_HPP

#include <curl/curl.h>
#include <string>


class Api {
private:
    CURL *curl;
    CURLcode curlResult;
    std::string username;
    std::uint32_t ipAddress;
public:
    //methods

    //getter
    const std::string &getUsername() const;
    uint32_t getIpAddress() const;

    //setter
    void setUsername(const std::string &username);
    void setIpAddress(uint32_t ipAddress);

};


#endif //HUEVITA_API_HPP
