#include <iostream>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon ();
        Weapon (std::string str);
        const std::string &getType();
        void    setType(std::string str);

};