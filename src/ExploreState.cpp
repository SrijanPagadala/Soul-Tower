#include "../header/ExploreState.hpp"

ExploreState::ExploreState(){
    level = 1; 
}

ExploreState::ExploreState(int levelToSet){
    level = levelToSet;
}

void ExploreState::display(){
    if(level == 1){ //first level exploration
        cout << "You wake up at the bottom of a large tower, very confused on how you got there." << endl;
        cout << "You notice a large spiral staircase, stretching to the top of the tower." << endl;
        cout << "At the base of the stairs, you see a sign that states \"SOUL TOWER: ENTER AT YOUR OWN RISK.\"" << endl;
        cout << "Being the tremendously smart traveler you are, you decide to step up the stairs." << endl;
        cout << "You hear a deep voice: \"WELCOME TO THE FIRST FLOOR\"" << endl;

    }

}