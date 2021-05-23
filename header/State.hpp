#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <iostream>
#include "cMain.h"
using namespace std;

class State {
    private:
    protected:
        int level;
    public:
        State() : level(1) {}
        State(int level) : level(level) {}
        virtual void display(cMain* gui) = 0;



};

#endif