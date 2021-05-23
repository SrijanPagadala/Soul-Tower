#ifndef __SHOPSTATE_HPP__
#define __SHOPSTATE_HPP__

#include <iostream>
#include "State.hpp"
using namespace std;


class ShopState: public State {
    private:

    public:
        ShopState();
        ShopState(int level);
        void display(cMain* gui);




};




#endif