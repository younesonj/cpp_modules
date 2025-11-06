#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Error: usage example [./rpn 5 4 * 3 +]" << std::endl, 1);

    try
    {
        RPN rpn(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}