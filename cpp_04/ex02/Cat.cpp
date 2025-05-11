#include "Cat.hpp"

Cat::Cat()
{
    type =  "Cat";
    std::cout << "Cat constructor called\n";
    brain = new Brain();
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called\n";   
}

Cat::Cat(const Cat &a)
{
    std::cout << "Cat Copy constructor called\n";
    type = a.type;
    brain = new Brain(*a.brain);
}

Cat& Cat::operator=(const Cat &a)
{
    if (this != &a)
    {
        delete brain;
        this->type = a.type;
        this->brain = new Brain(*a.brain);
    }
    return (*this);
}

void Cat::makeSound() const
{ 
    std::cout << "Meow\n";
}
