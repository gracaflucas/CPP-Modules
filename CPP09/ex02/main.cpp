#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<std::string> args(argv + 1, argv + argc);
    try {
        PmergeMe::run(args);
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
