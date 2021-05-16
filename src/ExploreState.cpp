#include "../header/ExploreState.hpp"

ExploreState::ExploreState(){
    level = 1;
    choice1 = "";
    choice2 = "";
}

ExploreState::ExploreState(int levelToSet){
    level = levelToSet;
    level = 1;
    choice1 = "";
    choice2 = "";
}

void ExploreState::display(){
    if(level == 1){ //first level exploration
        cout << "You wake up at the bottom of a large tower, very confused on how you got there." << endl;
        cout << "You notice a large spiral staircase, stretching to the top of the tower." << endl;
        cout << "At the base of the stairs, you see a sign that states \"SOUL TOWER: ENTER AT YOUR OWN RISK.\"" << endl;
        cout << "Being the tremendously smart traveler you are, you decide to step up the stairs." << endl;
        cout << "You see a sign that states: \"WELCOME TO THE FIRST FLOOR\"" << endl;
        cout << endl;
        cout << "As you walk through the corridoors of the first floor, you see a bright light coming from a room." << endl;
        cout << "You decide to walk closer to the bright lit room, and notice that the room is actually split into two rooms with two doors." << endl;
        cout << "Although both rooms have a shining light creeping through the doors, you notice distinct differences between the rooms." << endl;
        cout << "You feel a small wave of heat coming from Room 1, and notice that the light in Room 1 is much darker than the light from Room 2." << endl;
        cout << endl;
        cout << "Which room to you decide to go in?" << endl;



    }

}