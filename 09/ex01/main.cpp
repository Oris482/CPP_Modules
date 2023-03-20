#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Only 1 argument" << std::endl;
        exit(1);
    }

    RPN rpnCalculator;

    rpnCalculator.calculate(argv[1]);
    return 0;
}
