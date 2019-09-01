//
// Created by Denis on 02.09.2019.
//

#ifndef OTUS_CPP_HW4_PRINT_IP_ISCONTAINER_H
#define OTUS_CPP_HW4_PRINT_IP_ISCONTAINER_H

template <typename T>
struct isContainer {
    static const bool value = false;
};

template <typename T, typename Alloc>
struct isContainer<std::vector<T, Alloc> > {
    static const bool value = true;
};


#endif //OTUS_CPP_HW4_PRINT_IP_ISCONTAINER_H
