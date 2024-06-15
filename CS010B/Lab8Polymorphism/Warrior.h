#pragma once

#include "Character.h"
#include <string> 
using namespace std; 

class Warrior : public Character{
    protected:
        string allegiance;

    public:
        Warrior(const string& name, double health, double attackStrength, string allegiance);
        void attack(Character&) override; 
};