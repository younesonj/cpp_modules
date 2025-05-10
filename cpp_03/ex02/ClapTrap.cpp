#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : Name("Unknown"), Hit_points(10), Energy_points(10), attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), Hit_points(10), Energy_points(10), attack_damage(0)
{
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
    std::cout << "Copy assignement constructor called" << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        this->Hit_points = other.Hit_points;
        this->Energy_points = other.Energy_points;
        this->attack_damage = other.attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        Energy_points--;
        std::cout << "ClapTrap " << Name << " attacks " << target
                  << ", causing " << attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " is exhausted and can't attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points == 0)
    {
        std::cout << "ClapTrap " << Name << " is already destroyed!" << std::endl;
        return;
    }

    unsigned int actual_damage = (amount > Hit_points) ? Hit_points : amount;
    Hit_points -= actual_damage;

    std::cout << "ClapTrap " << Name << " lost " << actual_damage
              << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        Energy_points--;
        Hit_points += amount;
        std::cout << "ClapTrap " << Name << " gets " << amount
                  << " hit points back!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " is exhausted and can't repair!" << std::endl;
    }
}