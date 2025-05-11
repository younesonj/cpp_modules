#include "Cat.hpp"

Cat::Cat()
{
    type =  "Cat";
    std::cout << "Cat constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";   
}

Cat::Cat(const Cat &a)
{
    std::cout << "Cat Copy constructor called\n";
    type = a.type;
}

Cat& Cat::operator=(const Cat &a)
{
    if (this != &a)
        this->type = a.type;
    return (*this);
}

void Cat::makeSound() const
{ 
    std::cout << "Meow\n";
}
