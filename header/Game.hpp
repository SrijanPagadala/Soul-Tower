#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
using namespace std;

class Game {
    private:
        double coins;
    public:
        double getCoins() { return coins; }
        void setCoins(double newAmount) { coins = newAmount; }
        void changeCoins(double amount) { coins += amount; }
        
};

#endif