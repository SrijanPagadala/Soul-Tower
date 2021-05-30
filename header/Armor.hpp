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
        defenseValue = 0.9;
        tier = 1;
    }
    Armor(cMain* gui) {
        this->gui = gui;
        defenseValue = 0.9;
        tier = 1;
    }
    
    double takeDamage(double damage) {
        double reducedDamage = damage * (defenseValue - (tier * -0.1));
        return reducedDamage;
    }

    void upgrade() {
        tier += 1;
    }

    virtual void update(cMain* gui) = 0;
    
};