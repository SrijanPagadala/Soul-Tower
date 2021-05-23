#ifndef __FIGHTSTATE_HPP__
#define __FIGHTSTATE_HPP__

#include <iostream>
#include "State.hpp"
using namespace std;


class FightState: public State {
    private:

    public:
        FightState();
        FightState(int level);
        void display(cMainMock* gui);




};




#endif