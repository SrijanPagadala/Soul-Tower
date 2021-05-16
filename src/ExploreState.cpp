#include "../header/ExploreState.hpp"

ExploreState::ExploreState(){
    level = 1;
    input = "";
    choice1 = "";
    choice2 = "";
    coinsEarned = 0;
    healthPotionsEarned = 0;
    damageTaken = 0;
}

ExploreState::ExploreState(int levelToSet){
    level = levelToSet;
    input = "";
    choice1 = "";
    choice2 = "";
    coinsEarned = 0;
    healthPotionsEarned = 0;
    damageTaken = 0;
}

void ExploreState::display(cMainMock* gui){
    if(level == 1){ //first level exploration
        gui->DisplayOut("You wake up at the bottom of a large tower, very confused on how you got there.\n");
        gui->DisplayOut("You faintly remember being sent on a quest to save something or someone... but you are unsure.\n");
        gui->DisplayOut("It seems like you have amnesia, with faint memories of why you are in this tower in the first place.\n");
        gui->DisplayOut("You notice you are equipped with weaponry and armor, you must be a warrior or hero.\n");
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
            gui->DisplayOut("However, you realize you are not fire-proof, merely fire-resistant - you take 5 damage!\n");
            gui->DisplayOut("-5 health\n");
            damageTaken += 5;
        } else {
            gui->DisplayOut("You open the door and see a pile of shining coins!\n");
            gui->DisplayOut("You happily decide to collect all of them in your pockets.\n");
            gui->DisplayOut("+200 coins\n");
            coinsEarned += 200;
        }


    }

}