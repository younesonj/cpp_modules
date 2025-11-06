#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <exception>
#include <ctime>
#include <cstdlib>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        double  timeVector;
        double  timeDeque;
    public:
        PmergeMe(char *av[]);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool insert_data(std::string s);
        void    sort_vec();
        void    sort_deque();
        void    printInfo(void) const;

};



#endif
