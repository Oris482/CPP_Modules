#include "Parser.hpp"

void Parser::parse(std::vector<int>& dest, int argc, char *argv[]) {
    std::string strBuffer;
    int argIdx = 1;
    int num;

    while (argIdx < argc) {
        try {
            num = std::stoi(argv[argIdx]);
            if (num < 0) throw std::out_of_range("num is not positice integer.");
            ++argIdx;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;;
            exit(1);
        }
        dest.push_back(num);
    }
}
