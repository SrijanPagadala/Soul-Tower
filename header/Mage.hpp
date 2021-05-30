#ifndef MAGE_H
#define MAGE_H

#include "CharacterType.hpp"


class Mage : public CharacterType{
private:
    int mana;

public:
    Mage() : mana(100) {}

    virtual void attackOutput(cMain* gui) {
        gui->DisplayOut("You shot a spell! *FWOOSH* \n");
    }

};

#endif