#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "Enemy.hpp"
using namespace std;

class CharacterType {
protected:
    double health;
    const double maxHealth = 100;
    Weapon* weapon;
    Armor* armor;


public:
    CharacterType() : weapon(nullptr), armor(nullptr), health(maxHealth) {}
    virtual void attack(Enemy* enemy);
    
    void takeDamage(double damage) {
        health -= damage;
    }

    void setArmor(Armor* armor) { this->armor = armor; }
    void setWeapon(Weapon* weapon) { this->weapon = weapon; }

};