#pragma once
#include "cMain.h"
#include <string>

class Armor {
protected:
    double defenseValue;
    int tier;
    cMain* gui;

public:
    Armor() {
        gui = nullptr;
        defenseValue = 1;
        tier = 1;
    }

    Armor(cMain* gui) {
        this->gui = gui;
        defenseValue = 0.9;
        tier = 1;
    }
    
    double takeDamage(double damage) {
        double reducedDamage = damage * (defenseValue);
        return reducedDamage;
    }

    void upgrade() {
        tier += 1;
        if (tier == 2) {
            defenseValue = 0.8;
        }
    }

    virtual void update(cMain* gui) = 0;
    
};