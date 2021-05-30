#pragma once

#include "Enemy.hpp"
#include "WarriorGoblin.hpp"
#include "MageGoblin.hpp"
#include "ArcherGoblin.hpp"

class Weapon {
    protected:
        double attackDamage;
        int tier;

    public:
        Weapon(){
            attackDamage = 20;
            tier = 20;
        }

        virtual double attack(Enemy* enemy) = 0;

};