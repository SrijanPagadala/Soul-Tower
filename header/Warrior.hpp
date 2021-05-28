#pragma once

#include "CharacterType.hpp"
using namespace std;

class Warrior : public CharacterType{
private: 
    int rage;

public:
    Warrior() : rage(100) {}

};