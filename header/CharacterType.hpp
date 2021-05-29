#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"

class CharacterType {
    protected:
        double health;
        double maxHealth;
        Weapon* weapon;
        Armor* armor;

    public:
        CharacterType() {
            maxHealth = 100;
            health = maxHealth;
            weapon = nullptr;
            armor = nullptr;
        }

        ~CharacterType() {
            delete weapon;
            delete armor;
        }
    
        void takeDamage(double damage) {
            health -= damage;
        }

        void setArmor(Armor* armor) { 
            this->armor = armor; 
        }

        void setWeapon(Weapon* weapon) { 
            this->weapon = weapon; 
        }

};