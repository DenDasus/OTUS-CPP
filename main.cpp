//
// Created by Denis on 01.09.2019.
//

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <tuple>

#include "isContainer.h"

void printIp(std::string string) {
    std::cout << string << std::endl;
}

template <typename Number, typename std::enable_if<std::is_integral<Number>::value, void*>::type = nullptr>
void printIp(Number num) {
    int size = sizeof(num);
    uint8_t* ptr = ((uint8_t*) &num);
    for(int i = size - 1; i >= 0; i--) {
        std::cout << std::to_string(*(ptr + i));
        if(i != 0) {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

//template <typename Container, typename C = typename std::enable_if<isContainer<Container>::value>::type>
//void printIp(Container container) {
//
//}

template <typename Container, typename std::enable_if<has_iterator<Container>::value
        && std::is_integral<typename Container::value_type>::value
        , void*>::type = nullptr>
void printIp(Container container) {

}

int main(int argc, char const *argv[]) {
    printIp(char(-1));
    printIp(short(0));
    printIp(int(2130706433));
    printIp(8875824491850138409);

    printIp(std::string("127.0.0.1"));
    printIp(std::vector<int>{127, 0, 0, 2});
    printIp(std::vector<std::string>{"127", "0, 0, 2"});
    printIp(std::list<int>{127, 0, 0, 3});
//
//    printIp(std::make_tuple(192, 168, 0, 0));
}