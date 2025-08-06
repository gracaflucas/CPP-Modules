#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn;
    int result = 0;
    if (rpn.evaluate(argv[1], result)) {
        std::cout << result << std::endl;
    } else {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}