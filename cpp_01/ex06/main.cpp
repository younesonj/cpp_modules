#include "Harl.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments\n";
        return (1);

    }
    Harl obj;
    obj.complain(av[1]);
}