#include "Array.hpp"
#include <string>
#include <iostream>

int main() {
    int* a = new int();
    std::cout << "Value of dynamically allocated int with new int(): " << *a << std::endl;
    delete a;

    Array<int> aArray;
    std::cout << "Size of empty array: " << aArray.size() << std::endl;

    Array<int> b(5);
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = (i + 1) * 10;

    std::cout << "b contents: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    Array<std::string> s(2);
    s[0] = "hello";
    s[1] = "world";

    std::cout << "s contents: ";
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    try {
        std::cout << b[10] << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
