#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    Hit_points = 100;
    Energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    ScavTrap::operator=(other);
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assignement constructor called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << Name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ScavTrap " << Name << " attacks " << target
                << ", causing " << attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << Name << " is exhausted!" << std::endl;
}