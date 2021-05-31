#include "../header/cMain.h"
#include "../header/MageFactory.hpp"
#include "../header/WarriorFactory.hpp"
#include "../header/ArcherFactory.hpp"
#include "../header/ExploreState.hpp"
#include "../header/FightState.hpp"
#include "../header/ShopState.hpp"

Game::~Game()
{
	wxCriticalSectionLocker enter(gui->m_pThreadCS);
	// the thread is being destroyed; make sure not to leave dangling pointers around
	gui->m_pThread = NULL;
}

double Game::getCoins() { 
	return coins; 
}

void Game::setCoins(double newAmount) { 
	coins = newAmount;
	gui->updateCoins(coins);
}

void Game::changeCoins(double amount) {
	coins += amount;
	if (coins < 0) {
		coins = 0;
	}
	gui->updateCoins(coins);
}

int Game::getPotions() { 
	return healthPotions; 
}

void Game::setPotions(double newAmount) { 
	healthPotions = newAmount; 
	gui->updateHealthPotions(healthPotions);
}

void Game::changePotions(double amount) { 
	healthPotions += amount; 
	if (healthPotions < 0) {
		healthPotions = 0;
	}
	gui->updateHealthPotions(healthPotions);
}

// Game Implementations
wxThread::ExitCode Game::Entry() {

	// Init Game
	start();
	wxThread::This()->Sleep(10);
	wxQueueEvent(gui, new wxThreadEvent(wxEVT_THREAD, MYTHREAD_UPDATE));
	
	
	// signal the event handler that this thread is going to be destroyed
	wxQueueEvent(gui, new wxThreadEvent(wxEVT_THREAD, MYTHREAD_COMPLETED));
	return (wxThread::ExitCode)0;
};

// Prior to gameplay player gets to select a class of their choosing
void Game::classSelection() {
	// Choose class prompt
	gui->DisplayOut("Choose character class to play \n");
	gui->DisplayOut("1. Warrior \n");
	gui->DisplayOut("2. Archer \n");
	gui->DisplayOut("3. Mage \n");
	std::string classChoice = gui->GetChoice();
	while (classChoice != "1" && classChoice != "2" && classChoice != "3") {
		gui->DisplayOut("INVALID INPUT\n");
		classChoice = gui->GetChoice();
	}

	// Get input for class
	CharacterTypeFactory* characterCreator = nullptr;

		if (classChoice == "1") {
			characterCreator = new WarriorFactory(gui);
			gui->setArmorIcon("warrior_copper_armor.png");
			gui->setWeaponIcon("sword.png");
			gui->DisplayOut("You've choosen to be a Warrior \n");
			
			
		}
		else if (classChoice == "2") { 
			characterCreator = new ArcherFactory(gui);
			gui->setArmorIcon("archer_leather_armor.png");
			gui->setWeaponIcon("bow.png");
			gui->DisplayOut("You've choosen to be a Archer \n");
			
		}
		else if (classChoice == "3") {
			characterCreator = new MageFactory(gui);
			gui->setArmorIcon("mage_amethyst_armor.png");
			gui->setWeaponIcon("wand.png");
			gui->DisplayOut("You've choosen to be a Mage \n");

		}


	if (characterCreator != nullptr) {
		player = characterCreator->createCharacter();
		player->setArmor(characterCreator->createArmor());
		player->setWeapon(characterCreator->createWeapon());
	}

	gui->updateHeart(100);
	delete characterCreator;
}

// Main place where logic for the game runs
void Game::start() {
	// Allows user to select their class before game starts
	classSelection();
	// Gameplay begins here
	for (int currLevel = 1; currLevel <= MaxLevel; currLevel++) {
		// Exploration state
		currState = new ExploreState(currLevel);
		currState->display(this, gui);
		delete currState;
		// Fight state
		if (enemy != nullptr) {
			currState = new FightState(currLevel);
			currState->display(this, gui);
			// if the battle is lost end the game
			if (gameOver) {
				break;
			}
		}

		delete currState;

		// Shop state
		currState = new ShopState(currLevel);
		currState->display(this, gui);
		delete currState;
		
	}
	if (!gameOver) {
		gui->DisplayOut("You are victorious.\n");
		gui->DisplayOut("As you go to claim your soul back, you hear rumbling.\n");
		gui->DisplayOut("You look behind you and The Soulkeeper is standing up, as if he was perfectly unharmed from the previous battle.\n");
		gui->DisplayOut("You are baffled.\n");
		gui->DisplayOut("Your soul whizzes past your face into the hands of The Soulkeeper.\n");
		gui->DisplayOut("Soulkeeper: \"What did I say, you mere mortal? I am immortal.\"\n");
		gui->DisplayOut("Soulkepper: \"We have been through this dozens of times.\"\n");
		gui->DisplayOut("Soulkeeper: \"Once again, the battle was quite enjoyable.\"\n");
		gui->DisplayOut("He laughs.\n");
		gui->DisplayOut("Soulkeeper: \"Thank you for keeping me entertained.\"\n");
		gui->DisplayOut("You are confused and in utter shock as he picks you up.\n");
		gui->DisplayOut("He chucks you down the stairs into floor three.\n");
		gui->DisplayOut("You crawl next to the potted plant, with little energy left.\n");
		gui->DisplayOut("He kicks you and the journal and pen fall out of your pocket.\n");
		gui->DisplayOut("You realize.\n");
		gui->DisplayOut("You know the truth now.\n");
		gui->DisplayOut("This journal is YOUR journal.\n");
		gui->DisplayOut("You have fought The Soulkeeper before.\n");
		gui->DisplayOut("Quickly, you flip to a new page in the journal, and you write as fast as you can.\n");
		gui->DisplayOut("\"DO NOT TRUST WILLIAM\"\n");
		gui->DisplayOut("\"DO NOT FORGET\"\n");
		gui->DisplayOut("\"REMEMBER... PLEASE... REMEMBER...\"\n");
		gui->DisplayOut("The Soulkeeper grabs you and stares into your eyes.\n");
		gui->DisplayOut("You see his eyes flash a blinding white light.\n");
		gui->DisplayOut("Soulkeeper: \"See you soon.\"\n");
		gui->DisplayOut("You wake up at the bottom of a large tower, very confused on how you got there.\n");
		gui->DisplayOut("You faintly remember being on a quest to save something or someone... but you are unsure.\n");
		gui->DisplayOut("It seems like you have amnesia, with faint memories of why you are in this tower in the first place.\n");
	}
	gui->DisplayOut("Game Over! \n");
	delete currState;
	currState = nullptr;

}


