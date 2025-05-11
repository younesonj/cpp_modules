#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{

    private:
        Brain *brain;
    public:
       Cat(); 
       ~Cat(); 
       Cat(const Cat &a); 
       Cat& operator=(const Cat &a); 
       void makeSound() const;
      
};

#endif