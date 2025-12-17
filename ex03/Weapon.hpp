#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    private:
        std::string type;

    public:
        Weapon(const std::string& newType);
        const std::string& getType();
        void setType(const std::string& newType);
};

#endif