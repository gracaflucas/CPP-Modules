#include "Serializer.hpp"

int main() {
    Data original;
    original.Num = 42;

    uintptr_t raw = Serializer::serialize(&original);
    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << &original << std::endl;
    std::cout << "Serialized value:  " << raw << std::endl;
    std::cout << "Recovered pointer: " << recovered << std::endl;
    std::cout << "Recovered Num:     " << recovered->Num << std::endl;

    if (recovered == &original)
        std::cout << "Success: Same pointer recovered!" << std::endl;
    else
        std::cout << "Failure: Pointer mismatch." << std::endl;

    return 0;
}
