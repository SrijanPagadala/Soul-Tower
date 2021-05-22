#include "../header/cMain.h"

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
	gui->DisplayOutput("Who goes there? \n");
	gui->GetChoice();
	gui->DisplayOutput("What? \n");

	std::string input = gui->GetChoice();
	
	if (input == "Bob") {
		gui->DisplayOutput("Hey Bob!? \n");
	}
	else {
		gui->DisplayOutput("Hey! Get lawn m8 \n");
	}
	
}