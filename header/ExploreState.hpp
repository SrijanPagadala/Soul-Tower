#ifndef __EXPLORESTATE_HPP__
#define __EXPLORESTATE_HPP__

#include <iostream>
#include "State.hpp"
using namespace std;


class ExploreState: public State {
    private:
        string input;
        string choice1;
        string choice2;

    public:
        ExploreState();
        ExploreState(int levelToSet);
        void display(Game* game, cMain* gui);


};
#endif