#pragma once

using namespace std;

class Entity {
protected:
    double health;
    const double maxHealth = 100; 
    double baseDamage;

public:
    virtual void attack(Entity* opp) = 0;

};

