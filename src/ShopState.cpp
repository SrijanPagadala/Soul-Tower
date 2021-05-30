#include "../header/ShopState.hpp"


ShopState::ShopState(){
    level = 1; 

}

ShopState::ShopState(int levelToSet){
    level = levelToSet;
    armorUpgradeCost = 200;
    potionCost = 75;
}

void ShopState::display(Game* game, cMain* gui) {
    string input = "";

    if (level == 1) {
        gui->DisplayOut("You come discover a set of stairs leading to the next floor.\n");
        gui->DisplayOut("You blink and then all of a sudden a short hunchback man in a suit with a briefcase appears.\n");
        gui->DisplayOut("You are surprised because you swear there was no one there a second ago but nonetheless he looks friendly so you are relieved to see him.\n");
        gui->DisplayOut("You approach him and ask who he is and what he is doing here.\n");
        gui->DisplayOut("He stays silent, but he opens his briefcase and motions to you to take a look.\n");
        gui->DisplayOut("In it, you see 2 buttons, the first is labled: UPGRADE ARMOUR - " + std::to_string(armorUpgradeCost) + " coins, the second is labled GET HEALTH POTION - " + std::to_string(potionCost) + " coins.\n");
        
        while (input != "3") {
            gui->DisplayOut("What do you decide to do?\n");
            string c1 = "1. Upgrade armor for " + std::to_string(armorUpgradeCost) + " coins.";
            string c2 = "2. Buy a health potion for " + std::to_string(potionCost) + " coins.";
            string c3 = "3. Leave and proceed up the stairs to the next floor.";

            gui->DisplayOut(c1 + "\n");
            gui->DisplayOut(c2 + "\n");
            gui->DisplayOut(c3 + "\n");


            input = gui->GetChoice();

            while (input != "1" && input != "2" && input != "3") {
                gui->DisplayOut("Invalid input, please enter \"1\", \"2\", or \"3\" \n");
                input = gui->GetChoice();
            }

            //if upgrade armor
            if (input == "1") {
            

            }

            // if buy health potions
            else if (input == "2") {
               

            }

            gui->DisplayOut("The man still appears to be motioning you towards the briefcase.\n");

        }

        gui->DisplayOut("You decide that you are ready to leave. You blink and suddenly the man disapears.\n");
        gui->DisplayOut("The man gives you creepy vibes and scares you a little bit because of his sudden appearances.\n");
        gui->DisplayOut("Nonetheless, you are grateful that there it at least someone in the tower who is not trying to murder you on sight.\n");
        gui->DisplayOut("This fills you with determination. You proceed up the stairs onto the next floor.\n")

    }



}