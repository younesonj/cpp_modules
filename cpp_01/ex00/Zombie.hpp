#include <iostream>

class Zombie {
    private :
        std::string name;
    public :
        Zombie(std::string str);
        ~Zombie(void);
        void    announce(void);
};

void        randomChump(std::string name);
Zombie*     newZombie(std::string name);

