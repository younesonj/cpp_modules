#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::set_name(std::string str)
{
    name = str;
}

Zombie::~Zombie(void)
{
    std::cout << name << " destroyed!\n";
}
