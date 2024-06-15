#include <iostream> 
#include <string>
using namespace std;

#include "Character.h"
#include "Wizard.h"

Wizard::Wizard(const string& name, double health, double attackStrength, int wizRank)
    :Character(WIZARD, name, health, attackStrength), wizRank(wizRank){}

void Wizard::attack(Character& enemy){
    double damageDealt = 0; 
    if (enemy.getType() == WIZARD){
        Wizard& opp = dynamic_cast<Wizard&>(enemy); 
        damageDealt = (double)attackStrength*((double)wizRank/(double)opp.wizRank);
    }
    else {
        damageDealt = (attackStrength);
    }
    enemy.damage(damageDealt);
    cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
    cout << enemy.getName() << " takes " << damageDealt << " damage." << endl; 
}