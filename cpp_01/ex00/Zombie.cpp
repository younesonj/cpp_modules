#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string str)
{
    name = str;
}

Zombie::~Zombie(void)
{
    std::cout << name << " destroyed!\n";
}
