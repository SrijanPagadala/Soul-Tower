#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <iostream>
#include "cMainMock.hpp"
using namespace std;

class State {
    private:
    protected:
        int level;
    public:
        State() : level(1) {}
        State(int level) : level(level) {}
        virtual void display(cMainMock* gui) = 0;



};

#endif