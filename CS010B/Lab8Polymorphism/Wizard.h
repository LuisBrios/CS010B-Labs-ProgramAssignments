#pragma once

#include "Character.h"
#include <string> 
using namespace std; 

class Wizard : public Character{
    protected:
        int wizRank; 

    public:
        Wizard(const string& name, double health, double attackStrength, int wizRank);
        void attack(Character&) override;     
};