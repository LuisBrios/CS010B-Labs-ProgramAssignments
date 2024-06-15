#include <iostream> 
#include <string>
using namespace std;

#include "Character.h"
#include "Elf.h"

Elf::Elf(const string& name, double health, double attackStrength, string family)
    :Character(ELF, name, health, attackStrength), family(family){}

void Elf::attack(Character& enemy){
    if (enemy.getType() == ELF){
        Elf& opp = dynamic_cast<Elf&>(enemy); 
        if (opp.family == family){
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        else {
            double damageDealt = ((health / MAX_HEALTH) * attackStrength);
            enemy.damage(damageDealt);
            cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
            cout << enemy.getName() << " takes " << damageDealt << " damage." << endl;             
        }
    }
    else {
        double damageDealt = ((health / MAX_HEALTH) * attackStrength);
        enemy.damage(damageDealt);
        cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
        cout << enemy.getName() << " takes " << damageDealt << " damage." << endl; 
    }
}