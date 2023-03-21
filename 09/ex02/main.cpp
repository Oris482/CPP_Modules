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

    /* 
        Case: vector<int>
    */
    // Data setting
    mergeVec.startTimer();
    for (std::vector<int>::const_iterator it = numVec.begin(); it != numVec.end(); ++it) {
        mergeVec.push_back(*it);
    }
    mergeVec.endTimer();
    mergeVec.setDataSettingTime();

    // Data sorting
    mergeVec.startTimer();
    mergeVec.sort(0, mergeVec.getSize());
    mergeVec.endTimer();
    mergeVec.setDataSortingTime();

    /* 
        Case: deque<int>
    */
    // Data setting
    mergeDeq.startTimer();
    for (std::vector<int>::const_iterator it = numVec.begin(); it != numVec.end(); ++it) {
        mergeDeq.push_back(*it);
    }
    mergeDeq.endTimer();
    mergeDeq.setDataSettingTime();

    // Data sorting
    mergeDeq.startTimer();
    mergeDeq.sort(0, mergeDeq.getSize());
    mergeDeq.endTimer();
    mergeDeq.setDataSortingTime();

    /*
        Print Result
    */
    // Original Data
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = numVec.begin(); it != numVec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Sorted Data
    std::cout << "After(Vec): ";
    mergeVec.printAllElements();
    std::cout << "After(Deq): ";
    mergeDeq.printAllElements();

    // Print Analysis
    mergeVec.printAnalysis("std::vector<int>");
    mergeDeq.printAnalysis("std::deque<int>");

    return 0;
}
