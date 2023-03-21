#pragma once

#ifndef PMERGEME_H__
# define PMERGEME_H__

# include <vector>
# include <deque>
# include <iostream>
# include <ctime>

# define MIN_CHUNK_SIZE 2

template <typename T>
class PmergeMe {
    protected:
        T _elements;

        virtual void mergeSort(size_t start, size_t end, size_t pivot) = 0;
        virtual void insertionSort(size_t start, size_t end) = 0;

        PmergeMe(void);

    public:
        virtual ~PmergeMe() {};

        virtual size_t getSize(void) const = 0;
        virtual void printAllElements(void) const = 0;
        virtual void push_back(int num) = 0;
        virtual void sort(size_t start, size_t end);
};

template <>
class PmergeMe<std::vector<int> > {
    private:
        std::vector<int> _elements;
        clock_t _startTime;
        clock_t _endTime;
        clock_t _dataSettingTime;
        clock_t _dataSortingTime;
        
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator= (const PmergeMe& src);

    public:
        PmergeMe(void);
        ~PmergeMe();

        virtual size_t getSize(void) const;
        virtual void printAllElements(void) const;
        virtual void push_back(int num);

        void startTimer(void);
        void endTimer(void);
        void setDataSettingTime(void);
        void setDataSortingTime(void);
        clock_t getProcessDuration(void) const;
        clock_t getDataSettingTime(void) const;
        clock_t getDataSortingTime(void) const;
        void printAnalysis(const std::string containerType) const;

        virtual void mergeSort(size_t start, size_t end, size_t pivot);
        virtual void insertionSort(size_t start, size_t end);
        virtual void sort(size_t start, size_t end);

};

template <>
class PmergeMe<std::deque<int> > {
    private:
        std::deque<int> _elements;
        clock_t _startTime;
        clock_t _endTime;
        clock_t _dataSettingTime;
        clock_t _dataSortingTime;

        PmergeMe(const PmergeMe& src);
        PmergeMe& operator= (const PmergeMe& src);

    public:
        PmergeMe(void);
        ~PmergeMe();

        virtual size_t getSize(void) const;
        virtual void printAllElements(void) const;
        virtual void push_back(int num);

        void startTimer(void);
        void endTimer(void);
        void setDataSettingTime(void);
        void setDataSortingTime(void);
        clock_t getProcessDuration(void) const;
        clock_t getDataSettingTime(void) const;
        clock_t getDataSortingTime(void) const;
        void printAnalysis(const std::string containerType) const;

        virtual void mergeSort(size_t start, size_t end, size_t pivot);
        virtual void insertionSort(size_t start, size_t end);
        virtual void sort(size_t start, size_t end);
};

#endif
