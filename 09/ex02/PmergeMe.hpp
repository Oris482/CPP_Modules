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
        
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator= (const PmergeMe& src);

    public:
        PmergeMe(void);
        ~PmergeMe();

        virtual size_t getSize(void) const;
        virtual void printAllElements(void) const;
        virtual void push_back(int num);

        void setStartTime(void);
        void setEndTime(void);
        clock_t getProcessDuration(void) const;

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

        PmergeMe(const PmergeMe& src);
        PmergeMe& operator= (const PmergeMe& src);

    public:
        PmergeMe(void);
        ~PmergeMe();

        virtual size_t getSize(void) const;
        virtual void printAllElements(void) const;
        virtual void push_back(int num);

        void setStartTime(void);
        void setEndTime(void);
        clock_t getProcessDuration(void) const;

        virtual void mergeSort(size_t start, size_t end, size_t pivot);
        virtual void insertionSort(size_t start, size_t end);
        virtual void sort(size_t start, size_t end);
};

#endif
