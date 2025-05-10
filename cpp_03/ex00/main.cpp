#include "ClapTrap.hpp"

int main ()
{
    ClapTrap obj1("p1"), obj2("p2");

    obj1.attack("p2");
    obj2.takeDamage(1337);
    obj2.beRepaired(1);

    return (0);
}