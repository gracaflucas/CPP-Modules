#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>
#include <string>

struct Data;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& copy);
        ~Serializer();
        Serializer& operator=(const Serializer& other);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif