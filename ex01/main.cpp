#include "Zombie.hpp"

int main(void)
{
    int zNumber = 5;
    Zombie *zombies = zombieHorde(zNumber, "Bob");

    for(int i = 0; i < zNumber; i++)
        zombies[i].announce();
    delete[] zombies;
    return (0);
}