#pragma once

#include "CharacterType.hpp"

using namespace std;

class Warrior : public CharacterType{
private: 
    int rage;

public:
    Warrior(cMain* gui) : CharacterType(gui), rage(100) {}

    double takeDamage(WarriorGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 1);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    double takeDamage(ArcherGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 1.5);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    double takeDamage(MageGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 2);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    virtual void attackOutput(cMain* gui) {
        gui->DisplayOut("You swung your sword! *HWOO* \n");
    }
};