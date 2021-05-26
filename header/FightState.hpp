#ifndef __FIGHTSTATE_HPP__
#define __FIGHTSTATE_HPP__

#include "State.hpp"
using namespace std;


class FightState: public State {
    private:

    public:
        FightState();
        FightState(int level);
        void display(cMain* gui);

};




#endif