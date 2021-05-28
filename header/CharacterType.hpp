#pragma once

#include "Entity.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
using namespace std;

class CharacterType : public Entity {
protected:
    Weapon* weapon;
    Armor* armor;


public:
    CharacterType() : weapon(nullptr), armor(nullptr) {}
    virtual void attack(Entity* opp) override;
    void setArmor(Armor* armor) { this->armor = armor; }
    void setWeapon(Weapon* weapon) { this->weapon = weapon; }

};