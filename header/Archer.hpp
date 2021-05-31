#pragma once

#include "CharacterType.hpp"

using namespace std;

class Archer : public CharacterType{
private:
    int arrows;

public:
    Archer(cMain* gui) : CharacterType(gui), arrows(100){}

    double takeDamage(WarriorGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 1.5);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    double takeDamage(ArcherGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 1);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    double takeDamage(MageGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 1.25);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    virtual void attackOutput(cMain* gui) {
        gui->DisplayOut("You shot your bow! *TWIP* \n");
    }
};