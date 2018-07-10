//
// Created by bouba on 10/07/2018.
//

#include "Api.hpp"


//getter
const std::string &Api::getUsername() const {
    return username;
}
void Api::setIpAddress(uint32_t ipAddress) {
    Api::ipAddress = ipAddress;
}

//setter
void Api::setUsername(const std::string &username) {
    Api::username = username;
}
uint32_t Api::getIpAddress() const {
    return ipAddress;
}

