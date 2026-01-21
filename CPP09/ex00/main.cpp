#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong Command Line Argument, try ./btc 'file'." << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.loadDatabase("data.csv");
    btc.processInput(argv[1]);
    return 0;
}