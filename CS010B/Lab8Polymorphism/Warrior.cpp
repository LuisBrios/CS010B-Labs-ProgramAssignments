#include <iostream> 
#include <string>

using namespace std;

#include "Character.h"
#include "Warrior.h"

Warrior::Warrior(const string& name, double health, double attackStrength, string allegiance)
    :Character(WARRIOR, name, health, attackStrength), allegiance(allegiance){}

void Warrior::attack(Character& enemy){
    if (enemy.getType() == WARRIOR){
        Warrior& opp = dynamic_cast<Warrior&>(enemy); 
        if (opp.allegiance == allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << enemy.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else{
            double damageDealt = ((health / MAX_HEALTH) * attackStrength);
            enemy.damage(damageDealt);
            cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
            cout << enemy.getName() << " takes " << damageDealt << " damage." << endl; 
        }
    }
    else {
        double damageDealt = ((health / MAX_HEALTH) * attackStrength);
        enemy.damage(damageDealt);
        cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
        cout << enemy.getName() << " takes " << damageDealt << " damage." << endl; 
    }
}