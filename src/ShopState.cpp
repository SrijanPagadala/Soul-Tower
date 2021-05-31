#include "../header/ShopState.hpp"
#include "../header/Armor.hpp"
#include "../header/CharacterType.hpp"


ShopState::ShopState(){
    level = 1; 
    armorUpgradeCost = 200;
    potionCost = 75;
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
        gui->DisplayOut("In it, you see 2 buttons, the first is labled: UPGRADE ARMOUR - " + std::to_string(armorUpgradeCost) + " coins, the second is labled HEALTH POTION - " + std::to_string(potionCost) + " coins.\n");
        
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
                if (game->getPlayer()->getArmor()->getTier() == 2) {
                    gui->DisplayOut("Your armor has already been upgraded. You press the button but nothing happens.\n");
                }

                else if (game->getCoins() < armorUpgradeCost) {
                    gui->DisplayOut("You press the button, but nothing happens.\n");
                    gui->DisplayOut("You don't have enough coins.\n");
                }

                else {
                    gui->DisplayOut("You press the button labled UPGRADE ARMOR.\n");
                    gui->DisplayOut("You look down and suddenly your armor changes colour.\n");
                    gui->DisplayOut("You can feel the magical power coming off the armor. You can tell it's now stronger.\n");
                    game->getPlayer()->getArmor()->upgrade();

                    gui->DisplayOut(std::to_string(armorUpgradeCost) + " coins from your pocket have dissapeared.\n");
                    gui->DisplayOut("-" + std::to_string(armorUpgradeCost) + " coins.\n");
                    game->changeCoins(-1 * armorUpgradeCost);
                }

            }

            // if buy health potions
            else if (input == "2") {
                if (game->getCoins() < potionCost) {
                    gui->DisplayOut("You press the button, but nothing happens.\n");
                    gui->DisplayOut("You don't have enough coins.\n");
                }

                else {
                    gui->DisplayOut("You press the button labled HEALTH POTION.\n");
                    gui->DisplayOut("You hand is now holding a potion as if it had always been there.\n");
                    gui->DisplayOut("You place in your pocket.\n");
                    game->changePotions(1);

                    gui->DisplayOut(std::to_string(potionCost) + " coins from your pocket have dissapeared.\n");
                    gui->DisplayOut("-" + std::to_string(potionCost) + " coins.\n");
                    game->changeCoins(-1 * potionCost);

                }

            }

            gui->DisplayOut("The man still appears to be motioning you towards the briefcase.\n");

        }

        gui->DisplayOut("You decide that you are ready to leave. You blink and suddenly the man disapears.\n");
        gui->DisplayOut("The man gives you creepy vibes and scares you a little bit because of his sudden appearance and dissapearance.\n");
        gui->DisplayOut("Nonetheless, you are grateful that there it at least someone in the tower who is not trying to murder you on sight.\n");
        gui->DisplayOut("This fills you with determination. You proceed up the stairs onto the next floor.\n");

    }



}