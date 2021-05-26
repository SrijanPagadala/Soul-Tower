#ifndef __SHOPSTATE_HPP__
#define __SHOPSTATE_HPP__

#include "State.hpp"

class ShopState: public State {
    public:
        ShopState();
        ShopState(int levelToSet);
        void display(cMain* gui);
};


#endif