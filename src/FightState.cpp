#include "../header/FightState.hpp"


FightState::FightState(){
    level = 1; 
}

FightState::FightState(int levelToSet){
    level = levelToSet;
}

void FightState::display(Game* game, cMain* gui) {
    // Starts battle
    battle(game, gui);
    // End battle message
    endBattle(gui);

}


void FightState::battle(Game* game, cMain* gui) {
    Enemy* enemy = game->getEnemy();
    CharacterType* player = game->getPlayer();

    if (enemy != nullptr && player != nullptr) {
        while (enemy->isAlive() && player->isAlive()) {
            // prompts for Players moves
            player->attackChoiceOutput(gui);
            // Gets player moves
            std::string attackChoice = gui->GetChoice();
            while (attackChoice != "1" || attackChoice != "2") {
                gui->DisplayOut("INVALID INPUT \n");
            }

            // Handles players moves
            if (attackChoice == "1") {
                player->attack(enemy);
            }
            else {
                if (game->getPotions() > 0) {
                    player->takeHealthPotion();
                    game->changePotions(-1);
                }
                

            // Enemy attacks
            if (enemy->isAlive()) {

            }
        }

        if (enemy->isAlive()) {
            gui->DisplayOut(enemy->getName() + " has bested you! \n");
        }
        else {
            gui->DisplayOut("You have defeated " + enemy->getName() + "! \n");
        }
    }
}

void FightState::endBattle(cMain* gui) {

}