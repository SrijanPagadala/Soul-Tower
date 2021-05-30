#pragma once
#include "cMain.h"
class Weapon;
class Armor;

class CharacterType {
    protected:
        double health;
        double maxHealth;
        Weapon* weapon;
        Armor* armor;
        cMain* gui;

    public:
        CharacterType(cMain* gui) {
            this->gui = gui;
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

            gui->updateHeart(health);
        }

        void setArmor(Armor* armor) {
            this->armor = armor;
        }

        void setWeapon(Weapon* weapon) {
            this->weapon = weapon;
        }

        Weapon* getWeapon() {
            return weapon;
        }

        bool isAlive() {
            return health > 0;
        }

        void attackChoiceOutput(cMain* gui) {
            gui->DisplayOut(" Battle Options: \n");
            gui->DisplayOut("1. Attack \n");
            gui->DisplayOut("2. Heal \n");
        }

        void takeHealthPotion() {
            health += 20;
            if (health > maxHealth) {
                health = maxHealth;
            }
        }

        virtual void attackOutput(cMain* gui) = 0;

};
