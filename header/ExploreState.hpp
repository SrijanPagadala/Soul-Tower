#ifndef __EXPLORESTATE_HPP__
#define __EXPLORESTATE_HPP__

#include <iostream>
#include "State.hpp"
using namespace std;


class ExploreState: public State {
    private:

    public:
        ExploreState();
        ExploreState(int level);
        void display();

};





#endif