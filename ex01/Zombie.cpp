#include "Zombie.hpp"

void    PrintOut(std::string str, bool newline)
{
    if (newline){
        std::cout << str << std::endl;
    }
    else {
        std::cout << str;
    }
}

void Zombie::announce(void)
{
    PrintOut(name, false);
    PrintOut(": BraiiiiiiinnnzzzZ...", true);
}

Zombie::Zombie()
{
    name = "";
}

Zombie::Zombie(std::string zombie_name)
{
    name = zombie_name;
}

Zombie::~Zombie()
{
    PrintOut("Zombie ", false);
    PrintOut(name, false);
    PrintOut(" Destroyed", true);
}

void Zombie::setName(std::string zombie_name)
{
    name = zombie_name;
}
