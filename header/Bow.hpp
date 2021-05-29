#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"

using namespace std;

class Bow : public Weapon {
public:
    Bow() {}
    void attack(WarriorGoblin* enemy);
    void attack(MageGoblin* enemy);
    void attack(ArcherGoblin* enemy);

};