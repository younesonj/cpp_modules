#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called\n";
    brain = new Brain();
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called\n"; 
}

Dog::Dog(const Dog &a)
{
    std::cout << "Dog Copy constructor called\n";
    type = a.type;
    brain = new Brain(*a.brain);
}

Dog& Dog::operator=(const Dog &a)
{
    if (this != &a)
    {
        delete brain;
        this->type = a.type;
        this->brain = new Brain(*a.brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof\n";
}
