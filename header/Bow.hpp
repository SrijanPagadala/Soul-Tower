#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"

using namespace std;

class Bow : public Weapon {
public:
    Bow() {}
    virtual double attack(WarriorGoblin* enemy) {
        double damageDealt = this->attackDamage * 0.8;
        enemy->takeDamage(damageDealt);
        return damageDealt;
    };
    virtual double attack(MageGoblin* enemy) {
        double damageDealt = this->attackDamage * 1.5;
        enemy->takeDamage(damageDealt);
        return damageDealt;
    };
    virtual double attack(ArcherGoblin* enemy) {
        double damageDealt = this->attackDamage * 1;
        enemy->takeDamage(damageDealt);
        return damageDealt;
    };
    virtual double attack(Enemy* enemy) {
        double damageDealt = this->attackDamage * 1;
        enemy->takeDamage(damageDealt);
        return damageDealt;
    };

};