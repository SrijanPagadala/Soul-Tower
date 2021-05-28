#pragma once

#include "CharacterType.hpp"
using namespace std;

class Mage : public CharacterType{
private:
    int mana;

public:
    Mage() : mana(100) {}

};