#include <iostream>

class Zombie {
    private :
        std::string name;
    public :
        void    set_name(std::string str);
        ~Zombie(void);
        void    announce(void);
};

Zombie* zombieHorde(int N, std::string name);