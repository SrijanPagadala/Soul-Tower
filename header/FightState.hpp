#ifndef __FIGHTSTATE_HPP__
#define __FIGHTSTATE_HPP__

#include "State.hpp"

class FightState: public State {
    private:
        int level;
    public:
        FightState(){};
        FightState(int level) : level(level) {};

        void battle(Game* game, cMain* gui);
        void endBattle(cMain* gui);

        void display(Game* game, cMain* gui);

};




#endif