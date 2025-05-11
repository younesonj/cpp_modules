#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n"; 
}

Dog::Dog(const Dog &a)
{
    std::cout << "Dog Copy constructor called\n";
    type = a.type;
}

Dog& Dog::operator=(const Dog &a)
{
    if (this != &a)
        this->type = a.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof\n";
}
