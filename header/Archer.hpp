#pragma once

#include "CharacterType.hpp"
using namespace std;

class Archer : public CharacterType{
private:
    int arrows;

public:
    Archer() : arrows(100) {}

    virtual void attackOutput(cMain* gui) {
        gui->DisplayOut("You shot your bow! *TWIP* \n");
    }
};