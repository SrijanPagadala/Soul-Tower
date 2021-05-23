#ifndef __EXPLORESTATE_HPP__
#define __EXPLORESTATE_HPP__

#include <iostream>
#include "State.hpp"
using namespace std;


class ExploreState: public State {
    private:
        string input;
        string choice1;
        string choice2;
        double coinsEarned;
        int healthPotionsEarned;
        double damageTaken;

    public:
        ExploreState();
        ExploreState(int level);
        void display(cMain* gui);

        double getCoinsEarned() { return coinsEarned; }
        double getHealthPotionsEarned() { return healthPotionsEarned; }
        double getDamageTaken() { return damageTaken; }

};





#endif