#include "../header/cMain.h"
#include <iostream>
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Soul Tower", wxPoint(), wxSize(800,600)){
	m_input = new wxTextCtrl(this, wxID_ANY, "Input", wxPoint(10, 500), wxSize(500, 30));
	m_output = new wxTextCtrl(this, wxID_HIGHEST + 2, "Input", wxPoint(10, 10), wxSize(500, 450), wxTE_READONLY);
	m_bt1 = new wxButton(this, wxID_HIGHEST + 1, "Click Me", wxPoint(500, 500), wxSize(150, 50));
	inputRecieved = false;
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
	m_input->AppendText(wxString("?"));
	input_choice = m_input->GetLineText(0);
	inputRecieved = true;
}

cMain::~cMain() {
	delete m_bt1;
	delete m_input;
}
