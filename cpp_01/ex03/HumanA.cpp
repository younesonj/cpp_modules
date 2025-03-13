#include "HumanA.hpp"

HumanA::HumanA (std::string str, Weapon &W) : name(str), weapon(W){};

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
};
