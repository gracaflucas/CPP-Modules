#include "iter.hpp"

template <typename T>
void print(const T& value) {
    std::cout << value << " ";
}

template <typename T>
void increment(T& value) {
    value++;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"one", "two", "three"};
    const int constArray[] = {10, 20, 30, 40};

    std::cout << "Original int array: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    iter(intArray, 5, increment<int>);

    std::cout << "After increment: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, 3, print<std::string>);
    std::cout << std::endl;

    std::cout << "Const int array: ";
    iter(constArray, 4, print<int>);
    std::cout << std::endl;

    return 0;
}