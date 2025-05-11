#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    Animal *animal[100];
    std::cout << "Creating animals" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            animal[i] = new Cat();
        }
        else
        {
            animal[i] = new Dog();
        }
    }
    
    std::cout << "***********************" << std::endl;
    std::cout << "Deleting animals" << std::endl;
    for (int i = 0; i < 10; i++)
        delete animal[i];



    return 0;
}

