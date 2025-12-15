#include "Zombie.hpp"

int main(void)
{
    randomChump("StackBob");
    Zombie *z = newZombie("HeapBob");
    z->announce();
    delete z;
    return (0);
}