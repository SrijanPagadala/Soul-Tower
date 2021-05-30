#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"
using namespace std;

class Wand : public Weapon {
    public:
        Wand() {}

        virtual double attack(Enemy* enemy) {
            double damageDealt = enemy->takeDamage(this, this->attackDamage);
            return damageDealt;
        };
};