#include "Zombie.hpp"

int main ()
{ 
    Zombie *zombie = zombieHorde(2147483647, "miki");
    if (!zombie)
        return (1);
    for (int i = 0; i < 2; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
}
