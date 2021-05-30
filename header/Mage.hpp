#pragma once

#include "CharacterType.hpp"
using namespace std;

class Mage : public CharacterType{
private:
    int mana;

public:
    Mage() : mana(100) {}

    virtual void attackChoiceOutput(cMain* gui) {
        gui->DisplayOut(" Battle Options: \n");
        gui->DisplayOut("1. Attack \n");
        gui->DisplayOut("2. Heal \n");
    }

    virtual void attackOutput(cMain* gui) {

    }

};