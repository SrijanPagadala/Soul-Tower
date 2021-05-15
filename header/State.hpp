#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <iostream>
using namespace std;

class State {
    private:
    protected:
        int level;
    public:
        State() : level(1) {}
        State(int level) : level(level) {}
        virtual void display() = 0;



};

#endif