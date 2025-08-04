#include "Span.hpp"
#include <cstdlib>

int main() {
    std::cout << "Subject test:" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    std::cout << "\nTesting exception on overfill:" << std::endl;
    try {
        sp.addNumber(42);
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\nTesting large input (10000 numbers):" << std::endl;
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i) {
        bigSpan.addNumber(i * 2);
    }
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    std::cout << "\nTesting addRange():" << std::endl;
    std::vector<int> values;
    for (int i = 0; i < 10; ++i)
        values.push_back(i * 5);
    Span rangeSpan(10);
    rangeSpan.addRange(values.begin(), values.end());
    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;

    return 0;
}
