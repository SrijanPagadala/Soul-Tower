#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include "State.hpp"
using namespace std;

class Game {
    private:
        double coins;
        int healthPotions;
        State* currState;
    public:
        Game() : coins(0), healthPotions(0), currState(nullptr) {}
        double getCoins() { return coins; }
        void setCoins(double newAmount) { coins = newAmount; }
        void changeCoins(double amount) { coins += amount; }

        int getPotions() { return healthPotions; }
        void setPotions(double newAmount) { healthPotions = newAmount; }
        void changePotions(double amount) { healthPotions += amount; }
        
};

#endif