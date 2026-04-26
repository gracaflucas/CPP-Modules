#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sys/time.h>
#include <cstdlib>
#include <climits>

class PmergeMe {
    private:
        static bool isNumber(const std::string& str);
        static void validateInput(const std::vector<std::string>& args, std::vector<int>& output);
        static void mergeInsertSortVector(std::vector<int>& vec);
        static void mergeInsertSortDeque(std::deque<int>& deq);
        static void printSequence(const std::string& label, const std::vector<int>& seq);
        static long getTime();

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copy);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& other);
        static void run(const std::vector<std::string>& args); 
};

#endif