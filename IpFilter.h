//
// Created by DenisK on 06.08.2019.
//

#ifndef OTUS_CPP_IPFILTER_H
#define OTUS_CPP_IPFILTER_H

#include <vector>
#include <iostream>

class IpAddr {
private:
    uint32_t ip;

public:
    uint32_t getIp() const {
        return ip;
    }

    void setIp(uint32_t ip) {
        this->ip = ip;
    }

    void setIp(std::string &ipAddrString) {

    }

    friend std::ostream &operator << (std::ostream &os, const IpAddr &ipAddr) {
        uint32_t ip = ipAddr.getIp();
        return os  << ((ip >> 24) & 0xFF) << '.' << ((ip >> 16) & 0xFF) << '.' << ((ip >> 8) & 0xFF) << '.' << (ip & 0xFF);
    }
};

class IpFilter {
private:
    std::vector<IpAddr> pool;
public:

};


#endif //OTUS_CPP_IPFILTER_H
