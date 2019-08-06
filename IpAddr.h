//
// Created by DenisK on 06.08.2019.
//

#ifndef OTUS_CPP_IPADDR_H
#define OTUS_CPP_IPADDR_H

#include <vector>
#include <string>
#include <iostream>
#include "Utils.h"

class IpAddr {
private:
    uint32_t ip;

    void setIp(std::vector<std::string> v) {
        if(v.size() == 4) {
            this->ip = std::stoi(v.at(0)) << 24 | std::stoi(v.at(1)) << 16 | std::stoi(v.at(2)) << 8 | std::stoi(v.at(3));
        }
    }

public:
    IpAddr(uint32_t ip) {
        this->ip = ip;
    }

    IpAddr(std::string ipAddrString) {
        setIp(Utils::split(ipAddrString, '.'));
    }

    uint32_t getIp() const {
        return ip;
    }

    friend std::ostream &operator << (std::ostream &os, const IpAddr& ipAddr) {
        uint32_t ip = ipAddr.getIp();
        return os  << ((ip >> 24) & 0xFF) << '.' << ((ip >> 16) & 0xFF) << '.' << ((ip >> 8) & 0xFF) << '.' << (ip & 0xFF);
    }

    bool operator < (const IpAddr& ipAddr2 ) const {
        return ip < ipAddr2.getIp();
    }

    bool operator > (const IpAddr& ipAddr2) const {
        return ip > ipAddr2.getIp();
    }
};

#endif //OTUS_CPP_IPADDR_H
