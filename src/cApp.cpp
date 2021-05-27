#include "../header/cApp.h"
#include <thread>

wxIMPLEMENT_APP(cApp);

cApp::cApp() {
	
}

cApp::~cApp() {

}

bool cApp::OnInit() {
	wxInitAllImageHandlers();
	m_frame_1 = new cMain();
	m_frame_1->Show();
	SetTopWindow(m_frame_1);
	m_frame_1->OnStartThread();
	return true;
}

BEGIN_EVENT_TABLE(cMain, wxFrame)	
	//EVT_CLOSE(cMain::OnClose)
	EVT_MENU(Minimal_Quit, cMain::OnQuit)
	EVT_MENU(THREAD_STOP, cMain::OnStopThread)
	EVT_BUTTON(BUTTON_Choice, cMain::SubmitChoice) // Tell the OS to run MainFrame::OnExit when
END_EVENT_TABLE() // The button is pressed
