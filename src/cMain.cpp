#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Soul Tower", wxPoint(), wxSize(800,600)){
	wxButton* m_bt1 = new wxButton(this, wxID_ANY, "Click Me", wxPoint(500, 500), wxSize(150, 50));
	wxTextCtrl* m_input = new wxTextCtrl(this, wxID_ANY, "Input", wxPoint(10, 500), wxSize(400, 30));
}

cMain::~cMain() {

}
