#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "IpAddr.h"

int main(int argc, char const *argv[])
{
    std::vector<IpAddr> ipPool;
    ipPool.push_back(IpAddr{"8.8.8.8"});
    ipPool.push_back(IpAddr{"192.168.0.1"});
    ipPool.push_back(IpAddr{"190.168.0.1"});
    ipPool.push_back(IpAddr{"55.37.0.1"});
    ipPool.push_back(IpAddr{"190.168.0.2"});
    ipPool.push_back(IpAddr{"190.11.0.2"});
//    for(std::string line; std::getline(std::cin, line);)
//    {
//        std::vector<std::string> v = Utils::split(line, '\t');
//        ipPool.push_back(IpAddr(v.at(0)));
//    }

    std::sort(ipPool.begin(), ipPool.end(), std::greater<IpAddr>());

    //Sorted
    for (IpAddr addr : ipPool) {
        std::cout << addr << std::endl;
    }

    // filter by first byte and output
    for (IpAddr addr : ipPool) {
        if(addr.isMetRequirements(1)) {
            std::cout << addr << std::endl;
        }
    }

    // filter by first and second bytes and output
    for (IpAddr addr : ipPool) {
        if(addr.isMetRequirements(46, 70)) {
            std::cout << addr << std::endl;
        }
    }

    // filter by any byte and output
    for (IpAddr addr : ipPool) {
        if(addr.isContain(46)) {
            std::cout << addr << std::endl;
        }
    }

    return 0;
}