#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"
using namespace std;

class Wand : public Weapon {
    public:
        Wand() {}
        virtual double attack(WarriorGoblin* enemy) {
            double damageDealt = this->attackDamage * 2;
            enemy->takeDamage(damageDealt);
            return damageDealt;
        };
        virtual double attack(MageGoblin* enemy) {
            double damageDealt = this->attackDamage * 1;
            enemy->takeDamage(damageDealt);
            return damageDealt;
        };
        virtual double attack(ArcherGoblin* enemy) {
            double damageDealt = this->attackDamage * 1.5;
            enemy->takeDamage(damageDealt);
            return damageDealt;
        };
        virtual double attack(Enemy* enemy) {
            double damageDealt = this->attackDamage * 1;
            enemy->takeDamage(damageDealt);
            return damageDealt;
        };
};