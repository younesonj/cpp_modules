#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    {
        Animal *a = new Dog();
        Animal *b = new Cat();

        std::cout << a->getType() << std::endl;
        std::cout << b->getType() << std::endl;

        a->makeSound();
        b->makeSound();

        delete a;
        delete b;
    }
    std::cout << "***************************" << std::endl;
    {
        WrongAnimal *a = new Wrongcat();
        std::cout << a->getType() << std::endl;
        a->makeSound();
        delete a;

    }



    return 0;
}