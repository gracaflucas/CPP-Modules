#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "Generated: A." << std::endl;
        return new A;
    }
    else if (r == 1) {
        std::cout << "Generated: B." << std::endl;
        return new B;
    }
    else {
        std::cout << "Generated: C." << std::endl;
        return new C;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Identified by pointer: A." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified by pointer: B." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified by pointer: C." << std::endl;
    else
        std::cout << "Identified by pointer: Unknown type." << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified by reference: A." << std::endl;
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified by reference: B." << std::endl;
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified by reference: C." << std::endl;
        return ;
    } catch (...) {}

    std::cout << "Identified by reference: Unknown type." << std::endl;
}

int main(void) {
    std::srand(std::time(0));

    Base* ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;

    return 0;
}
