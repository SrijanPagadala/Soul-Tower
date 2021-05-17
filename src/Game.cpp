#include "../header/cMain.h"

// Game Implementations
wxThread::ExitCode Game::Entry() {
	while (!TestDestroy())
	{
		// Init Game
		gui->DisplayOutput("Who goes there? \n");
		gui->GetChoice();
		gui->DisplayOutput("What? \n");

	}
	// signal the event handler that this thread is going to be destroyed
	wxQueueEvent(gui, new wxThreadEvent(wxEVT_THREAD, MYTHREAD_COMPLETED));
	return (wxThread::ExitCode)0;
};