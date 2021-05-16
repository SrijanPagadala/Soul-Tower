#include "../header/ExploreState.hpp"

ExploreState::ExploreState(){
    level = 1;
    input = "";
    choice1 = "";
    choice2 = "";
}

ExploreState::ExploreState(int levelToSet){
    level = levelToSet;
    level = 1;
    input = "";
    choice1 = "";
    choice2 = "";
}

void ExploreState::display(cMainMock* gui){
    if(level == 1){ //first level exploration
        gui->DisplayOut("You wake up at the bottom of a large tower, very confused on how you got there.\n");
        gui->DisplayOut("You notice a large spiral staircase, stretching to the top of the tower.\n");
        gui->DisplayOut("At the base of the stairs, you see a sign that states \"SOUL TOWER: ENTER AT YOUR OWN RISK.\"\n");
        gui->DisplayOut("Being the tremendously smart traveler you are, you decide to step up the stairs.\n");
        gui->DisplayOut("You see a sign that states: \"WELCOME TO THE FIRST FLOOR\"\n");
        gui->DisplayOut("\n");
        gui->DisplayOut("As you walk through the corridoors of the first floor, you see a bright light coming from a room.\n");
        gui->DisplayOut("You decide to walk closer to the bright lit room, and notice that the room is actually split into two rooms with two doors.\n");
        gui->DisplayOut("Although both rooms have a shining light creeping through the doors, you notice distinct differences between the rooms.\n");
        gui->DisplayOut("You feel a small wave of heat coming from Room 1, and notice that the light in Room 1 is much darker than the light from Room 2.\n");
        gui->DisplayOut("\n");
        gui->DisplayOut("Which room do you decide to go in?\n");
        choice1 = "1. Room 1";
        choice2 = "2. Room 2";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        if(input == "1"){
            gui->DisplayOut("You open the door and walk straight into a pool of lava!\n");
            gui->DisplayOut("You discover that your skin is fire-resistant, and you manage to get out alive.\n");
            gui->DisplayOut("However, you realize you are not fire-proof, merely fire-resistant - you take 10 damage!\n");
        }


    }

}