#include "HumanB.hpp"

class HumanA
{
    private :
        std::string name;
        Weapon  &weapon;
    public :
        HumanA (std::string str, Weapon &W);
        
        void    attack();
};
