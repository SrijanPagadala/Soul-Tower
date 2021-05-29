#pragma once

//#include <string>
//#include "Enemy.hpp"


class Weapon {
    protected:
        double attackDamage;
        int tier;

    public:
        Weapon(){
            attackDamage = 20;
            tier = 20;
        }

        //virtual attack();

};