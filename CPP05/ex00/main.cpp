#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.increment(); // should be grade 1 now
        std::cout << a << std::endl;

        a.increment(); // should throw exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------" << std::endl;

    try {
        Bureaucrat b("Bob", 151); // invalid grade, should throw
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
