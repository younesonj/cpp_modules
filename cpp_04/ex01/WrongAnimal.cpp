#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("Animal")
{
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    std::cout << "WrongAnimal copy constructor called\n";
    type = a.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
    if (this != &a)
        this->type = a.type;
    return *this;
}

void  WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a generic sound!\n";
}

const std::string& WrongAnimal::getType() const
{
    return (type);
}
