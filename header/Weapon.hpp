#pragma once

#include <string>
#include "Enemy.hpp"


using namespace std;

class Weapon {
protected:
    double attackDamage;
    int tier;
    virtual void attack() = 0;
};