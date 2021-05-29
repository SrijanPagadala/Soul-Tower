#pragma once

#include <string>
#include "Enemy.hpp"


using namespace std;

class Weapon {
protected:
    double attackDamage;
    int tier;

public:
    Weapon() : attackDamage(20), tier(0) {}

};