#pragma once

#include "Character.h"
using namespace std; 

class Elf : public Character{
    protected:
        string family;

    public: 
        Elf(const string& name, double health, double attackStrength, string family);
        void attack(Character&) override;     
};