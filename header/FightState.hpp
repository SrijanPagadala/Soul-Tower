#ifndef __FIGHTSTATE_HPP__
#define __FIGHTSTATE_HPP__

#include "State.hpp"
#include "Enemy.hpp"
using namespace std;


class FightState: public State {
    private:
        Enemy* enemy;
    public:
        FightState() : enemy(nullptr) {};
        FightState(Enemy* enemy, int level) : enemy(enemy) {};

        void fight();
        void endFight();
        void display(Game* game, cMain* gui);

};




#endif