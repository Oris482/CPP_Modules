#include "PmergeMe.hpp"

// vector<int>
PmergeMe<std::vector<int> >::PmergeMe(void) {}

PmergeMe<std::vector<int> >::~PmergeMe() {}

size_t PmergeMe<std::vector<int> >::getSize(void) const {
    return _elements.size();
}

void PmergeMe<std::vector<int> >::printAllElements(void) const {
    std::vector<int>::const_iterator it = _elements.begin();

    for(; it != _elements.end(); ++it) {
        if (it != _elements.begin()) std::cout << " ";

        std::cout << *it;
    }
    std::cout << "\n";
}

void PmergeMe<std::vector<int> >::push_back(int num) {
    try {
        _elements.push_back(num);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;;
        exit(1);
    }
}

void PmergeMe<std::vector<int> >::startTimer(void) {
    _startTime = clock();
}

void PmergeMe<std::vector<int> >::endTimer(void) {
    _endTime = clock();
}

void PmergeMe<std::vector<int> >::setDataSettingTime() {
    _dataSettingTime = getProcessDuration();
}

void PmergeMe<std::vector<int> >::setDataSortingTime() {
    _dataSortingTime = getProcessDuration();
}
        
clock_t PmergeMe<std::vector<int> >::getProcessDuration(void) const {
    return (_endTime - _startTime);
}

clock_t PmergeMe<std::vector<int> >::getDataSettingTime(void) const {
    return _dataSettingTime;
}

clock_t PmergeMe<std::vector<int> >::getDataSortingTime(void) const {
    return _dataSortingTime;
}

void PmergeMe<std::vector<int> >::printAnalysis(const std::string containerType) const {
    std::cout << "Time to process a range of " << getSize() << " elements with " << containerType << std::endl;
    std::cout << "* For data setting: " << getDataSettingTime() << "ms" << std::endl;
    std::cout << "* For data sorting: " << getDataSortingTime() << "ms" << std::endl;
}

void PmergeMe<std::vector<int> >::mergeSort(size_t start, size_t end, size_t pivot) {
    const std::vector<int> leftVec(_elements.begin() + start, _elements.begin() + pivot);
    const std::vector<int> rightVec(_elements.begin() + pivot, _elements.begin() + end);
    std::vector<int>::size_type leftIdx = 0;
    std::vector<int>::size_type rightIdx = 0;

    for(size_t i = start; i < end; ++i) {
        if (leftIdx == leftVec.size()) _elements[i] = rightVec.at(rightIdx++);
        else if (rightIdx == rightVec.size()) _elements[i] = leftVec.at(leftIdx++);
        else if (leftVec.at(leftIdx) <= rightVec.at(rightIdx))
            _elements[i] = leftVec.at(leftIdx++);
        else
            _elements[i] = rightVec.at(rightIdx++);
    }
}

void PmergeMe<std::vector<int> >::insertionSort(size_t start, size_t end)  {
    for(size_t i = start; i < end - 1; ++i) {
        int temp = _elements[i + 1];
        size_t j = i + 1;
        for (; j > start; --j) {
            if (temp > _elements[j - 1]) break ;

            _elements[j] = _elements[j - 1];
        }
        _elements[j] = temp;
    }
}

void PmergeMe<std::vector<int> >::sort(size_t start, size_t end) {
    if (getSize() < 2) return ;

    if (end - start > MIN_CHUNK_SIZE) {
        int pivot = (start + end) / 2;
        sort(start, pivot);
        sort(pivot, end);
        mergeSort(start, end, pivot);
    } else {
        insertionSort(start, end);
    }
}

// deque<int>
PmergeMe<std::deque<int> >::PmergeMe(void) {}

PmergeMe<std::deque<int> >::~PmergeMe() {}

size_t PmergeMe<std::deque<int> >::getSize(void) const {
    return _elements.size();
}

void PmergeMe<std::deque<int> >::printAllElements(void) const {
    std::deque<int>::const_iterator it = _elements.begin();

    for(; it != _elements.end(); ++it) {
        if (it != _elements.begin()) std::cout << " ";
        
        std::cout << *it;
    }
    std::cout << "\n";
}

void PmergeMe<std::deque<int> >::push_back(int num) {
    try {
        _elements.push_back(num);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;;
        exit(1);
    }
}

void PmergeMe<std::deque<int> >::startTimer(void) {
    _startTime = clock();
}

void PmergeMe<std::deque<int> >::endTimer(void) {
    _endTime = clock();
}

void PmergeMe<std::deque<int> >::setDataSettingTime(void) {
    _dataSettingTime = getProcessDuration();
}

void PmergeMe<std::deque<int> >::setDataSortingTime(void) {
    _dataSortingTime = getProcessDuration();
}
        
clock_t PmergeMe<std::deque<int> >::getProcessDuration(void) const {
    return (_endTime - _startTime);
}

clock_t PmergeMe<std::deque<int> >::getDataSettingTime(void) const {
    return _dataSettingTime;
}

clock_t PmergeMe<std::deque<int> >::getDataSortingTime(void) const {
    return _dataSortingTime;
}

void PmergeMe<std::deque<int> >::printAnalysis(const std::string containerType) const {
    std::cout << "Time to process a range of " << getSize() << " elements with " << containerType << std::endl;
    std::cout << "* For data setting: " << getDataSettingTime() << "ms" << std::endl;
    std::cout << "* For data sorting: " << getDataSortingTime() << "ms" << std::endl;
}

void PmergeMe<std::deque<int> >::mergeSort(size_t start, size_t end, size_t pivot) {
    const std::deque<int> leftVec(_elements.begin() + start, _elements.begin() + pivot);
    const std::deque<int> rightVec(_elements.begin() + pivot, _elements.begin() + end);
    std::deque<int>::size_type leftIdx = 0;
    std::deque<int>::size_type rightIdx = 0;

    for(size_t i = start; i < end; ++i) {
        if (leftIdx == leftVec.size()) _elements[i] = rightVec.at(rightIdx++);
        else if (rightIdx == rightVec.size()) _elements[i] = leftVec.at(leftIdx++);
        else if (leftVec.at(leftIdx) <= rightVec.at(rightIdx))
            _elements[i] = leftVec.at(leftIdx++);
        else
            _elements[i] = rightVec.at(rightIdx++);
    }
}

void PmergeMe<std::deque<int> >::insertionSort(size_t start, size_t end)  {
    for(size_t i = start; i < end - 1; ++i) {
        int temp = _elements[i + 1];
        size_t j = i + 1;
        for (; j > start; --j) {
            if (temp > _elements[j - 1]) break ;

            _elements[j] = _elements[j - 1];
        }
        _elements[j] = temp;
    }
}

void PmergeMe<std::deque<int> >::sort(size_t start, size_t end) {
    if (getSize() < 2) return ;

    if (end - start > MIN_CHUNK_SIZE) {
        int pivot = (start + end) / 2;
        sort(start, pivot);
        sort(pivot, end);
        mergeSort(start, end, pivot);
    } else {
        insertionSort(start, end);
    }
}
