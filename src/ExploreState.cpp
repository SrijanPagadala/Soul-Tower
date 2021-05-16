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
        gui->DisplayOut("You faintly remember being on a quest to save something or someone... but you are unsure.\n");
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
        gui->DisplayOut("Which room do you decide to go in?\n"); //CHOICE 1: LAVA ROOM OR COINS ROOM
        choice1 = "1. Room 1";
        choice2 = "2. Room 2";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        if(input == "1"){ //They walk into a room of lava and take 5 damage
            gui->DisplayOut("You open the door and walk straight into a pool of lava!\n");
            gui->DisplayOut("You discover that your skin is fire-resistant, and you manage to get out alive.\n");
            gui->DisplayOut("However, you realize you are not fire-proof, merely fire-resistant - you take 5 damage!\n");
            gui->DisplayOut("-5 health\n");
            damageTaken += 5;
        } else { //They walk into a room of coins and gain 200 coins
            gui->DisplayOut("You open the door and see a pile of shining coins!\n");
            gui->DisplayOut("You happily decide to collect all of them in your pockets.\n");
            gui->DisplayOut("+200 coins\n");
            coinsEarned += 200;
        }
        gui->DisplayOut("\n");
        gui->DisplayOut("You continue traveling further throughout the floor.\n");
        gui->DisplayOut("You are still very much confused as to how you got here and the purpose of your peresence in the tower.\n");
        gui->DisplayOut("However, it seems you are drawn towards the top floor.\n");
        gui->DisplayOut("You walk past another room, when you hear faint whispering coming from inside.\n");
        if(input == "1"){ //If they walked into the lava last time
            gui->DisplayOut("Remembering what happened with the last room you entered, you were unsure of whether to enter this room.\n");
            gui->DisplayOut("You slowly walk past the room, but, as the whipsering gets louder--you cannot resist.\n");
            gui->DisplayOut("Bracing yourself for the worst, you open the door and walk in.\n");
        } else { //If they walked into the coins last time
            gui->DisplayOut("Remembering what happened with the last room you entered, you eagerly opened the door and walked in.\n");
        }
        gui->DisplayOut("You see a goblin whispering to itself in the corner of the room.\n");
        gui->DisplayOut("You decide to walk closer to it.\n");
        gui->DisplayOut("Suddenly, the goblin turns around and screams in a mystic language.\n");
        gui->DisplayOut("Startled, you take out your weapon and pin it to the wall, ready to kill it.\n");
        gui->DisplayOut("Do you kill the goblin?\n"); //CHOICE 2: Kill or spare the goblin
        choice1 = "1. Kill the goblin";
        choice2 = "2. Let the goblin live";
        gui->DisplayOut(choice1 + "\n");
        gui->DisplayOut(choice2 + "\n");
        input = gui->GetChoice();
        if(input == "1"){ //Player kills goblin
            gui->DisplayOut("You go through with it and kill the goblin.\n");
            gui->DisplayOut("You find 100 coins in its pockets.\n");
            gui->DisplayOut("+100 coins\n");
            coinsEarned += 100;
        } else { //Player spares goblin
            gui->DisplayOut("You decide to let the goblin live and you put your weapon away.\n");
            gui->DisplayOut("As you let your guard down, the goblin reaches into its pockets.\n");
            gui->DisplayOut("It pulls out 50 coins and... eats them.\n");
            gui->DisplayOut("You are confused and concerned, but then you see that the goblin's eyes glow yellow.\n");
            gui->DisplayOut("The goblin starts screaming louder in its mystic language and bites you.\n");
            gui->DisplayOut("-5 health.\n");
            damageTaken += 5;
            gui->DisplayOut("In pain, you pull out your weapon and kill the goblin.\n");
            gui->DisplayOut("You find 50 coins in its pockets.\n");
            gui->DisplayOut("+50 coins\n");
            coinsEarned += 500;
        }
        gui->DisplayOut("You look around the room, very confused as to what just happened.\n");
        gui->DisplayOut("On one of the walls, you see a note.\n");
        gui->DisplayOut("\"PLEASE DO NOT FEED THE COIN GOBLINS!\"\n");
        gui->DisplayOut("You realize that this goblin has an appetite for coins - and is NOT friendly.\n");


    }

}