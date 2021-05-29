#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"
using namespace std;

class Sword : public Weapon {
public:
    Sword() {}
    void attack(WarriorGoblin* enemy);
    void attack(MageGoblin* enemy);
    void attack(ArcherGoblin* enemy);

};