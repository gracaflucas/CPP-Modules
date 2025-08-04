#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void testVector() {
    std::cout << "--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i)
        vec.push_back(i * 10); // 10, 20, 30, 40, 50

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(vec, 99);
    } catch (std::exception& e) {
        std::cout << "Not found in vector: " << e.what() << std::endl;
    }
}

void testList() {
    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i)
        lst.push_back(i); // 1, 2, 3, 4, 5

    try {
        std::list<int>::iterator it = easyfind(lst, 4);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(lst, -1);
    } catch (std::exception& e) {
        std::cout << "Not found in list: " << e.what() << std::endl;
    }
}

void testDeque() {
    std::cout << "\n--- Testing with std::deque ---" << std::endl;
    std::deque<int> dq;
    for (int i = 1; i <= 3; ++i) {
        dq.push_back(i * 100);
    }

    try {
        std::deque<int>::iterator it = easyfind(dq, 200);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(dq, 500);
    } catch (std::exception& e) {
        std::cout << "Not found in deque: " << e.what() << std::endl;
    }
}

int main() {
    testVector();
    testList();
    testDeque();
    return 0;
}
