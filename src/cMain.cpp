#include "../header/cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Soul Tower", wxPoint(), wxSize(800,600)){
	m_bt1 = new wxButton(this, 6000, "Click Me", wxPoint(500, 500), wxSize(150, 50));
	m_input = new wxTextCtrl(this, wxID_ANY, "Input", wxPoint(10, 500), wxSize(400, 30));
}


void cMain::SubmitChoice(wxCommandEvent& event) {
	m_input->AppendText(wxString("Hello"));
}

cMain::~cMain() {
	delete m_bt1;
	delete m_input;
}
