#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{

    public:
       Cat(); 
       ~Cat(); 
       Cat(const Cat &a); 
       Cat& operator=(const Cat &a); 
       void makeSound() const;
      
};

#endif