#include "../header/cMain.h"
#include <iostream>


wxThread::ExitCode Game::Entry(){
	 while (!TestDestroy())
	 {
		 // ... do a bit of work...
		 //wxQueueEvent(m_pHandler, new wxThreadEvent(wxEVT_COMMAND_MYTHREAD_UPDATE));
		 
		 gui->DisplayOutput("Who goes there? \n");
		 gui->GetChoice();
		 gui->DisplayOutput("What? \n");
		 //wxQueueEvent(gui, new wxThreadEvent(wxEVT_THREAD, MYTHREAD_UPDATE));

	 }
	 // signal the event handler that this thread is going to be destroyed
	 // NOTE: here we assume that using the m_pHandler pointer is safe,
	 //       (in this case this is assured by the MyFrame destructor)
	 //wxQueueEvent(m_pHandler, new wxThreadEvent(wxEVT_COMMAND_MYTHREAD_COMPLETED));
	 wxQueueEvent(gui, new wxThreadEvent(wxEVT_THREAD, MYTHREAD_COMPLETED));
	 return (wxThread::ExitCode)0;     // success
};


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Soul Tower", wxPoint(), wxSize(800,600)), m_pThread (NULL){
	m_input = new wxTextCtrl(this, wxID_ANY, "--Soul Tower-- \n", wxPoint(10, 500), wxSize(500, 30));
	m_output = new wxTextCtrl(this, wxID_HIGHEST + 2, "Input", wxPoint(10, 10), wxSize(500, 450), wxTE_READONLY | wxTE_MULTILINE);
	m_bt1 = new wxButton(this, wxID_HIGHEST + 1, "Click Me", wxPoint(500, 500), wxSize(150, 50));
	wxButton* START = new wxButton(this, 700, "Click Me", wxPoint(600, 10), wxSize(150, 50));
	inputRecieved = false;
}

cMain::~cMain() {
    delete m_bt1;
    delete m_input;
}

wxString cMain::GetChoice() {
	bool sendInput = inputRecieved;
	while (!sendInput) {
		sendInput = inputRecieved;
	}
	inputRecieved = false;

	return input_choice;
}

void cMain::SubmitChoice(wxCommandEvent& event) {
	m_input->Clear();
	input_choice = m_input->GetLineText(0);
	m_output->AppendText(input_choice + "\n");
	inputRecieved = true;
}

void cMain::DisplayOutput(std::string msg) {
	m_output->AppendText(wxString(msg));
}

void cMain::StopThread()
{
	wxCriticalSectionLocker enter(m_pThreadCS);
	if (m_pThread) // does the thread still exist?
	{
		wxLogDebug("MYFRAME: deleting thread");

		if (m_pThread->Delete() != wxTHREAD_NO_ERROR)
			wxLogError("Can't delete the thread!");
	}
}

// event handlers
void cMain::OnStartThread(wxCommandEvent& event)
{
	
	if (m_pThread != NULL) return;
	
	m_pThread = new Game(this);
	if (m_pThread->Run() != wxTHREAD_NO_ERROR)
	{
		wxLogError("Can't create the thread!");
		delete m_pThread;
		m_pThread = NULL;
	}
	// after the call to wxThread::Run(), the m_pThread pointer is "unsafe":
	// at any moment the thread may cease to exist (because it completes its work).
	// To avoid dangling pointers OnThreadExit() will set m_pThread
	// to NULL when the thread dies.
}


void cMain::OnStopThread(wxCommandEvent& WXUNUSED(event))
{
	StopThread();
}


void cMain::OnThreadCompletion(wxThreadEvent& evt)
{
	wxLogDebug("MYFRAME: MyThread exited!");
}


void cMain::OnThreadUpdate(wxThreadEvent& evt)
{
	wxLogDebug("MYFRAME: MyThread update...");
}


void cMain::OnClose(wxCloseEvent&)
{
	StopThread();

	// now wait till thread is actually destroyed
	while (1)
	{
		{ // was the ~MyThread() function executed?
			wxCriticalSectionLocker enter(m_pThreadCS);
			if (!m_pThread) break;
		}

		// wait for thread completion
		wxThread::This()->Sleep(1);
	}

	Destroy();
}

void cMain::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true is to force the frame to close
	Close(true);
}

void cMain::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxString::Format
	(
		"Welcome to %s!\n"
		"\n"
		"This is the minimal wxWidgets sample\n"
		"running under %s.",
		wxVERSION_STRING,
		wxGetOsDescription()
	),
		"About wxWidgets minimal sample",
		wxOK | wxICON_INFORMATION,
		this);
}



