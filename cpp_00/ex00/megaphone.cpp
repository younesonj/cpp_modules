#include <iostream>

int main (int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 0;
        while (++i < ac)
        {
            size_t j = 0;
            while (av[i][j])
                std::cout << (char)toupper(av[i][j++]);
        }
    }
    std::cout << std::endl;
    return (0);
}
