#include "../header/cApp.h"
#include <thread>

wxIMPLEMENT_APP(cApp);

cApp::cApp() {
	
}

cApp::~cApp() {

}

bool cApp::OnInit() {
	m_frame_1 = new cMain();
	m_frame_1->Show();
	SetTopWindow(m_frame_1);
	return true;
}

BEGIN_EVENT_TABLE(cMain, wxFrame)	
	EVT_BUTTON(700, cMain::OnStartThread)
	EVT_BUTTON(BUTTON_Choice, cMain::SubmitChoice) // Tell the OS to run MainFrame::OnExit when
	EVT_CLOSE(cMain::OnClose)
END_EVENT_TABLE() // The button is pressed

