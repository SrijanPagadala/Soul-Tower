#include "../header/cApp.h"

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
	EVT_BUTTON(BUTTON_Choice, cMain::SubmitChoice) // Tell the OS to run MainFrame::OnExit when
END_EVENT_TABLE() // The button is pressed