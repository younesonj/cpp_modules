#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error: usage example [./PmergeMe 5 4 3 7]" << std::endl, 1);

    try
    {
        PmergeMe p = PmergeMe(av);
        p.sort_vec();
        p.sort_deque();
        p.printInfo();


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}