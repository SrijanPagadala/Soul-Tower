#pragma once

#include "Weapon.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"
using namespace std;

class Wand : public Weapon {
    public:
        Wand() {}
        virtual double attack(WarriorGoblin* enemy);
        virtual double attack(MageGoblin* enemy);
        virtual double attack(ArcherGoblin* enemy);
        virtual double attack(Enemy* enemy);
};