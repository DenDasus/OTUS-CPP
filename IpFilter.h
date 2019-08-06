//
// Created by DenisK on 06.08.2019.
//

#ifndef OTUS_CPP_IPFILTER_H
#define OTUS_CPP_IPFILTER_H

#include <vector>
#include <string>
#include <iostream>
#include "Utils.h"

class IpAddr {
private:
    uint32_t ip;

public:
    IpAddr(uint32_t ip) {
        this->ip = ip;
    }

    IpAddr(std::string ipAddrString) {
        std::vector<std::string> v = Utils::split(ipAddrString, '.');

        if(v.size() == 4) {
            this->ip = std::stoi(v.at(0)) << 24 | std::stoi(v.at(1)) << 16 | std::stoi(v.at(2)) << 8 | std::stoi(v.at(3));
        }
    }

    uint32_t getIp() const {
        return ip;
    }

    void setIp(uint32_t ip) {
        this->ip = ip;
    }

    void setIp(std::string &ipAddrString) {

    }

    friend std::ostream &operator << (std::ostream &os, const IpAddr& ipAddr) {
        uint32_t ip = ipAddr.getIp();
        return os  << ((ip >> 24) & 0xFF) << '.' << ((ip >> 16) & 0xFF) << '.' << ((ip >> 8) & 0xFF) << '.' << (ip & 0xFF);
    }

    bool operator < (const IpAddr& ipAddr2) {
        std::cout << "tp1" << std::endl;
        return ip < ipAddr2.getIp();
    }

    bool operator == (const IpAddr& ipAddr2) {
        std::cout << "tp2" << std::endl;
        return ip == ipAddr2.getIp();
    }
};

class IpFilter {
private:
    std::vector<IpAddr> pool;
public:

};


#endif //OTUS_CPP_IPFILTER_H
