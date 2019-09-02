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

template <typename T >
struct has_iterator {
    template <typename U >
    static char test (typename U::iterator* x );
    template <typename U >
    static long test (U* x);
    static const bool value = sizeof (test<T>(0)) == 1;
};

#endif //OTUS_CPP_HW4_PRINT_IP_ISCONTAINER_H
