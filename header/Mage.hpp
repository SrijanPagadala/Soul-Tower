#ifndef MAGE_H
#define MAGE_H

#include "CharacterType.hpp"


class Mage : public CharacterType{
private:
    int mana;

public:
    Mage(cMain* gui) : CharacterType(gui), mana(100) {}

    double takeDamage(WarriorGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 2);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    double takeDamage(ArcherGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 1.25);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    double takeDamage(MageGoblin*, double damage) {
        double damageTotal = armor->takeDamage(damage * 1);
        CharacterType::takeDamage(damageTotal);
        return damageTotal;
    }

    virtual void attackOutput(cMain* gui) {
        gui->DisplayOut("You shot a spell! *FWOOSH* \n");
    }

};

#endif