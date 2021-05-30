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
            // Player attacks

            // Enemy attacks
            if (enemy->isAlive()) {

            }
        }

        if (enemy->isAlive()) {
            gui->DisplayOut(enemy->getName() + " has bested you! \n");
        }
        else {
            gui->DisplayOut("You have won the fight! \n");
        }
    }
}

void FightState::endBattle(cMain* gui) {

}