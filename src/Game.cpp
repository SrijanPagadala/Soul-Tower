#include "../header/cMain.h"
#include "../header/ExploreState.hpp"

// Game Implementations
wxThread::ExitCode Game::Entry() {

	// Init Game
	start();
	
	// signal the event handler that this thread is going to be destroyed
	wxQueueEvent(gui, new wxThreadEvent(wxEVT_THREAD, MYTHREAD_COMPLETED));
	return (wxThread::ExitCode)0;
};

// Main place where logic for the game runs
void Game::start() {
	currState = new ExploreState(1);
	currState->display(this, gui);
	//gui->setArmorIcon("warrior_diamond_armor.png");
	delete currState;
	currState = nullptr;
}