#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char *av[])
{
    for (size_t i = 1; av[i]; i++)
    {
        std::string temp(av[i]);
        if (temp.empty() || !insert_data(temp))
            throw (std::runtime_error("Error: invalid input!"));
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->_vector = other._vector;
    this->_deque = other._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::insert_data(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (!isdigit(s[i]))
            return (false);
    long l = std::atol(s.c_str());
    if (l > 2147483647)
        return (false);
    _vector.push_back(static_cast<int>(l));
    _deque.push_back(static_cast<int>(l));
    return (true);
}

void    PmergeMe::sort_vec()
{
    clock_t start = clock();
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] > _vector[i + 1])
            std::swap(_vector[i], _vector[i + 1]);
    }
    std::vector<int>small;
    std::vector<int>large;
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        small.push_back(_vector[i]);
        large.push_back(_vector[i + 1]);
    }
    if (_vector.size() % 2 != 0)
        small.push_back(_vector.back());
    for (size_t i = 1; i < small.size(); ++i)
    {
        int current = small[i];
        size_t position = i;
        while (position > 0 && small[position - 1] > current)
        {
            small[position] = small[position - 1];
            --position;
        }
        small[position] = current;
    }
    for (size_t i = 0; i < large.size(); ++i)
    {
        int val = large[i];
        size_t pos = 0;
    
        while (pos < small.size() && small[pos] < val)
            ++pos;
        small.insert(small.begin() + pos, val);
    }
    _vector = small;
    timeVector = double(clock() - start) / CLOCKS_PER_SEC;
}

void    PmergeMe::sort_deque()
{
    clock_t start = clock();
    for (size_t i = 0; i + 1 < _deque.size(); i += 2)
    {
        if (_deque[i] > _deque[i + 1])
            std::swap(_deque[i], _deque[i + 1]);
    }
    std::deque<int>small;
    std::deque<int>large;
    for (size_t i = 0; i + 1 < _deque.size(); i += 2)
    {
        small.push_back(_deque[i]);
        large.push_back(_deque[i + 1]);
    }
    if (_deque.size() % 2 != 0)
        small.push_back(_deque.back());
    for (size_t i = 1; i < small.size(); ++i)
    {
        int current = small[i];
        size_t position = i;
        while (position > 0 && small[position - 1] > current)
        {
            small[position] = small[position - 1];
            --position;
        }
        small[position] = current;
    }
    for (size_t i = 0; i < large.size(); ++i)
    {
        int val = large[i];
        size_t pos = 0;
    
        while (pos < small.size() && small[pos] < val)
            ++pos;
        small.insert(small.begin() + pos, val);
    }
    _deque = small;
    timeDeque = double(clock() - start) / CLOCKS_PER_SEC;
}

void        PmergeMe::PmergeMe::printInfo(void) const
{
    std::cout << "After : ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size() 
            << " elements with std::[vector] : " 
            << (timeVector * 1e6) << " us" << std::endl;

    std::cout << "Time to process a range of " << _vector.size() 
            << " elements with std::[deque]  : " 
            << (timeDeque * 1e6) << " us" << std::endl;
}
