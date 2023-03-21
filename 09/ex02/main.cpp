#include "PmergeMe.hpp"
#include "Parser.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout <<  "At least 1 argument" << std::endl;
        exit(1);
    }

    std::vector<int> numVec;
    PmergeMe<std::vector<int> > mergeVec;
    PmergeMe<std::deque<int> > mergeDeq;

    Parser::parse(numVec, argc, argv);

    // vector<int>
    mergeVec.setStartTime();
    for (std::vector<int>::const_iterator it = numVec.begin(); it != numVec.end(); ++it) {
        mergeVec.push_back(*it);
    }
    mergeVec.sort(0, mergeVec.getSize());
    mergeVec.setEndTime();

    // deque<int>
    mergeDeq.setStartTime();
    for (std::vector<int>::const_iterator it = numVec.begin(); it != numVec.end(); ++it) {
        mergeDeq.push_back(*it);
    }
    mergeDeq.sort(0, mergeDeq.getSize());
    mergeDeq.setEndTime();

    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = numVec.begin(); it != numVec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "After(Vec): ";
    mergeVec.printAllElements();
    std::cout << "After(Deq): ";
    mergeDeq.printAllElements();
    std::cout << "Time to process a range of " << mergeVec.getSize() << " elements with std::vector<int> : " << mergeVec.getProcessDuration()  << "ms" << std::endl;
    std::cout << "Time to process a range of " << mergeDeq.getSize() << " elements with std::deque<int> : " << mergeDeq.getProcessDuration()  << "ms" << std::endl;

    return 0;
}
