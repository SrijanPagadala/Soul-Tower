#pragma once

#include "CharacterType.hpp"
using namespace std;

class Mage : public CharacterType{
private:
    int mana;

public:
    Mage() : mana(100) {}

    virtual void attackOutput(cMain* gui) {
        gui->DisplayOut("You shot a spell! *FWOOSH* \n");
    }

};