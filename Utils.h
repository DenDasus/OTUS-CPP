//
// Created by DenisK on 06.08.2019.
//

#ifndef OTUS_CPP_UTILS_H
#define OTUS_CPP_UTILS_H

#include <vector>

class Utils {
public:
    static std::vector<std::string> split(const std::string &str, char delim)
    {
        std::vector<std::string> parts;
        auto start = 0;
        auto stop = str.find_first_of(delim);

        while(stop != std::string::npos)
        {
            parts.push_back(str.substr(start, stop - start));

            start = stop + 1;
            stop = str.find_first_of(delim, start);
        }

        parts.push_back(str.substr(start));

        return parts;
    }

};


#endif //OTUS_CPP_UTILS_H
