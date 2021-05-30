#ifndef __FIGHTSTATE_HPP__
#define __FIGHTSTATE_HPP__

#include "State.hpp"
#include "Enemy.hpp"
#include "CharacterType.hpp"


class FightState: public State {
    private:
        int level;
        Enemy* enemy;
    public:
        FightState() : enemy(nullptr) {};
        FightState(int level) : level(level) {};

        void battle(Game* game, cMain* gui);
        void endBattle(cMain* gui);

        void display(Game* game, cMain* gui);

};




#endif