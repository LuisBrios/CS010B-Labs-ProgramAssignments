#include <iostream> 
#include <string>
#include "Character.h"
using namespace std; 

Character::Character(HeroType typeName, const string& charName, double charHP, double charStrength)
    :type(typeName), name(charName), health(charHP), attackStrength(charStrength){}

HeroType Character::getType() const{
    return type; 
}

const string& Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return static_cast<int>(health); 
}

void Character::damage(double d){
    this->health -= d; 
}

bool Character::isAlive() const{
    if (getHealth() > 0){
        return true;
    }
    else {
        return false;
    } 
}