#pragma once
#include "cMain.h"
#include "Armor.hpp"
class Weapon;
class WarriorGoblin;
class MageGoblin;
class ArcherGoblin;

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
    
        virtual void takeDamage(double damage) {
            health -= damage;
            if (health < 0) {
                health = 0;
            }
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

        Armor* getArmor() {
            return armor;
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
            gui->updateHeart(health);
        }
        void revive() {
            health = maxHealth;
            gui->updateHeart(health);
        }
        virtual void attackOutput(cMain* gui) = 0;
        virtual double takeDamage(WarriorGoblin*, double) = 0;
        virtual double takeDamage(MageGoblin*, double) = 0;
        virtual double takeDamage(ArcherGoblin*, double) = 0;
};
