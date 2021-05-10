#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	m_frame_1 = new cMain();
	m_frame_1->Show();
	return true;
}
