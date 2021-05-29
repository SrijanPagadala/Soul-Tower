#pragma once

#include "CharacterType.hpp"
using namespace std;

class Archer : public CharacterType{
private:
    int arrows;

public:
    Archer() : arrows(100) {}

};