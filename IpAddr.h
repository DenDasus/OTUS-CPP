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

    uint8_t getOctet(uint8_t oct) {
        return (ip >> 8 * (4 - oct)) & 0xFF;
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

    bool isMetRequirements(int oct1 = -1, int oct2 = -1, int oct3 = -1, int oct4 = -1) {
        uint32_t mask = 0;
        mask |= (oct1 == -1 ? getOctet(1) : oct1) << 24;
        mask |= (oct2 == -1 ? getOctet(2) : oct2) << 16;
        mask |= (oct3 == -1 ? getOctet(3) : oct3) << 8;
        mask |= (oct3 == -1 ? getOctet(4) : oct4);

        return ip == mask;
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
