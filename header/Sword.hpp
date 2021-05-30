#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"
using namespace std;

class Sword : public Weapon {
public:
    Sword() {}

    virtual double attack(Enemy* enemy) {
        //double damageDealt = this->attackDamage * 1;
        double damageDealt = enemy->takeDamage(this, attackDamage);
        return damageDealt;
    };

};