#include "../header/cMain.h"
#include <Windows.h>

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Soul Tower", wxPoint(), wxSize(800,600)), m_pThread (NULL){
	// Main Menu Elements
	m_input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 500), wxSize(400, 30));
	m_output = new wxTextCtrl(this, wxID_HIGHEST + 2, "--Soul Tower-- \n", wxPoint(10, 10), wxSize(500, 480), wxTE_READONLY | wxTE_MULTILINE);
	m_bt1 = new wxButton(this, wxID_HIGHEST + 1, "Submit", wxPoint(410, 500), wxSize(100, 30));

	// Inits current icons to be displayed
	heartIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "heart.png"), wxBITMAP_TYPE_PNG), wxPoint(510, 410), wxSize(32, 32), 0, wxString("HeartImg"));
	coinIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "coin.png"), wxBITMAP_TYPE_PNG), wxPoint(574, 410), wxSize(32, 32), 0, wxString("CoinImg"));
	armorIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "no_armor.png"), wxBITMAP_TYPE_PNG), wxPoint(520, 10), wxSize(121, 388), 0, wxString("ArmorImg"));
	// Inits text to be displayed
	coinCountText = new wxStaticText(this, wxID_ANY, wxString("x0"), wxPoint(542, 422), wxSize(12, 12));
	coinCountText->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	
	heartCountText = new wxStaticText(this, wxID_ANY, wxString("x0"), wxPoint(606, 422), wxSize(12, 12));
	heartCountText->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	
	inputRecieved = false;
}

cMain::~cMain() {
    delete m_bt1;
	delete m_output;
    delete m_input;
	delete heartIcon;
	delete armorIcon;
}

void cMain::setArmorIcon(std::string armorChoiceFileName) {
	if (armorIcon != nullptr) {
		delete armorIcon;
	}

	armorIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + armorChoiceFileName), wxBITMAP_TYPE_PNG), wxPoint(520, 10), wxSize(121, 388), 0, wxString("ArmorImg"));
}

std::string cMain::GetChoice() {
	bool sendInput = inputRecieved;
	while (!sendInput) {
		sendInput = inputRecieved;
	}
	inputRecieved = false;
	
	return input_choice.ToStdString();
}

void cMain::SubmitChoice(wxCommandEvent& event) {
	input_choice = m_input->GetLineText(0);
	m_output->AppendText(input_choice + "\n");
	m_input->Clear();
	inputRecieved = true;
}

void cMain::DisplayOut(std::string msg) {
	m_output->AppendText(wxString(msg));
	Sleep(2000);
}

void cMain::OnStartThread()
{
	if (m_pThread != NULL) return;
	
	m_pThread = new Game(this);
	if (m_pThread->Run() != wxTHREAD_NO_ERROR)
	{
		wxLogError("Can't create the thread!");
		delete m_pThread;
		m_pThread = NULL;
	}
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

void cMain::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true is to force the frame to close
	Close(true);
}



