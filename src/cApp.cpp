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
	m_frame_1->OnStartThread();
	SetTopWindow(m_frame_1);
	return true;
}

BEGIN_EVENT_TABLE(cMain, wxFrame)	
	EVT_BUTTON(BUTTON_Choice, cMain::SubmitChoice) // Tell the OS to run MainFrame::OnExit when
	EVT_CLOSE(cMain::OnClose)
END_EVENT_TABLE() // The button is pressed

