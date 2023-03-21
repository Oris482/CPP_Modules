#include "Parser.hpp"

void Parser::parse(std::vector<int>& dest, int argc, char *argv[]) {
    std::string strBuffer;
    int argIdx = 1;
    int num;

    while (argIdx < argc) {
        std::istringstream ss(argv[argIdx]);

        while (getline(ss, strBuffer, ' ')) {
            if (strBuffer.length() == 0) continue ;
            try {
                num = std::stoi(strBuffer);
                if (num < 0) throw std::out_of_range("num is not positice integer.");
                
                dest.push_back(num);
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;;
                exit(1);
            }
        }
        ++argIdx;
    }
}
