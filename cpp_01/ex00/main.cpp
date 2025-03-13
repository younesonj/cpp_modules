#include "Zombie.hpp"


int main ()
{
    randomChump("hada f stack");

    Zombie *zombie = newZombie("hada fl heap");
    zombie->announce();

    delete(zombie);
    
    return (0);
}