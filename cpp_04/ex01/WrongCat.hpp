#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"


class Wrongcat : public WrongAnimal{
    
    public :
        ~Wrongcat();
        Wrongcat();
        Wrongcat(const Wrongcat& a);
        Wrongcat& operator=(const Wrongcat& a);
        void makeSound() const;
    

};

#endif