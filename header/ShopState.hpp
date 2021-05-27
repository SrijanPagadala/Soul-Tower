#ifndef __SHOPSTATE_HPP__
#define __SHOPSTATE_HPP__

#include "State.hpp"

class ShopState: public State {
    public:
        ShopState();
        ShopState(int levelToSet);
        void display(Game* game, cMain* gui);
};


#endif