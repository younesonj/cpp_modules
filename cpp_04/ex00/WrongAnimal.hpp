#ifndef  WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{

    protected :
        std::string type;

    public :
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &a);
        WrongAnimal& operator=(const WrongAnimal &a);
        void makeSound() const;
        const std::string& getType() const;

    
};


#endif