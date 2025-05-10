#include "ScavTrap.hpp"

int main ()
{
    ScavTrap scav("Guardian");
    ScavTrap scav2 = scav;
    std::cout << std::endl;

    scav2.guardGate();
    scav2.attack("p2");
}