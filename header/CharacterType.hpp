#pragma once

#include "Entity.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
using namespace std;

class CharacterType : public Entity {
private:
    Weapon* weapon;
    Armor* armor;
public:
    virtual void attack(Entity* opp) override;

};