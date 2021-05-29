#include "../header/cMain.h"
#include "../header/ExploreState.hpp"
#include "../header/MageFactory.hpp"
#include "../header/ArcherFactory.hpp"
#include "../header/WarriorFactory.hpp"


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

	// Get input for class
	bool validInput = false;
	CharacterTypeFactory* characterCreator;

	while (!validInput) {
		if (classChoice == "1") {
			characterCreator = new WarriorFactory();
			gui->DisplayOut("You've choosen to be a Warrior \n");
			validInput = true;
			
		}
		else if (classChoice == "2") { 
			characterCreator = new ArcherFactory();
			gui->DisplayOut("You've choosen to be a Archer \n");
			validInput = true;
		}
		else if (classChoice == "3") {
			characterCreator = new MageFactory();
			gui->DisplayOut("You've choosen to be a Mage \n");
			validInput = true;
		}
		else {
			gui->DisplayOut("INVALID INPUT");
		}
	}

	player = characterCreator->createCharacter();
	player->setArmor(characterCreator->createArmor());
	player->setWeapon(characterCreator->createWeapon());

	delete characterCreator;
}

// Main place where logic for the game runs
void Game::start() {
	currState = new ExploreState(1);
	currState->display(this, gui);
	//gui->setArmorIcon("warrior_diamond_armor.png");
	delete currState;
	currState = nullptr;
}


