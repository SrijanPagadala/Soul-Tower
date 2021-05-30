#pragma once

#include "CharacterType.hpp"

using namespace std;

class Warrior : public CharacterType{
private: 
    int rage;

public:
    Warrior() : rage(100) {}

    virtual void attackOutput(cMain* gui) {
        gui->DisplayOut("You swung your sword! *HWOO* \n");
    }
};