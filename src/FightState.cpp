#include "../header/FightState.hpp"
#include "../header/Enemy.hpp"
#include "../header/CharacterType.hpp"
#include "../header/Weapon.hpp"

FightState::FightState(){
    level = 1; 
}

FightState::FightState(int levelToSet) : State(levelToSet){
   
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
        gui->DisplayOut("You v.s. " + enemy->getName() + "\n");
        while (enemy->isAlive() && player->isAlive()) {
            // Player Attacks
            player->attackChoiceOutput(gui); // prompts for Players moves

            // Gets player moves
            std::string attackChoice = gui->GetChoice();             
            while (attackChoice != "1" && attackChoice != "2") {
                gui->DisplayOut("INVALID INPUT \n");
                attackChoice = gui->GetChoice();
            }

            // Handles players moves
            if (attackChoice == "1") {
                double damageDone = player->getWeapon()->attack(enemy);
                player->attackOutput(gui);
                gui->DisplayOut("You've dealt: " + std::to_string(damageDone) + " damage! \n");
                gui->DisplayOut(enemy->getName() + " current HP: " + std::to_string(enemy->getHealth()) + "\n");
            }
            else {
                if (game->getPotions() > 0) {
                    player->takeHealthPotion();
                    game->changePotions(-1);
                    gui->DisplayOut("*GLUG GLUG* How refreshing, you've gained some health \n");
                }
                else {
                    gui->DisplayOut("*POP* Oh wait.. you dont have any health potions \n");
                }
            }
                

            // Enemy attacks
            if (enemy->isAlive()) {
                double damageDone = enemy->attack(player);
                enemy->attackOutput(gui);
                gui->DisplayOut(enemy->getName() + " dealt: " + std::to_string(damageDone) + " damage! \n");
            }
        }

        if (enemy->isAlive()) {
            gui->DisplayOut(enemy->getName() + " has bested you! \n");
            game->gameOver = true;
        }
        else {
            gui->DisplayOut("You have defeated " + enemy->getName() + "! \n");
            gui->DisplayOut("Lucky you, they had some coins. \n");
            gui->DisplayOut("+200 coins \n");
            game->changeCoins(200);
            game->gameOver = false;
           
        }

        delete game->getEnemy();
        game->setEnemy(nullptr);
    }
}

void FightState::endBattle(cMain* gui) {

}