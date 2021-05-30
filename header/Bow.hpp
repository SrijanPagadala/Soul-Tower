#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"

using namespace std;

class Bow : public Weapon {
public:
    Bow() {}

    virtual double attack(Enemy* enemy) {
        double damageDealt = this->attackDamage * 1;
        enemy->takeDamage(this, damageDealt);
        return damageDealt;
    };

};