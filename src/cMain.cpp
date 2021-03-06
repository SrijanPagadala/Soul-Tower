#include "../header/cMain.h"
#include <Windows.h>

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Soul Tower", wxPoint(), wxSize(800,600)), m_pThread (NULL){
	// Main Menu Elements
	m_input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 500), wxSize(400, 30));
	m_output = new wxTextCtrl(this, wxID_HIGHEST + 2, "--Soul Tower-- \n", wxPoint(10, 10), wxSize(500, 480), wxTE_READONLY | wxTE_MULTILINE);
	m_bt1 = new wxButton(this, wxID_HIGHEST + 1, "Submit", wxPoint(410, 500), wxSize(100, 30));

	// Inits current icons to be displayed
	heartIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "heart.png"), wxBITMAP_TYPE_PNG), wxPoint(510, 500), wxSize(32, 32), 0, wxString("HeartImg"));
	coinIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "coin.png"), wxBITMAP_TYPE_PNG), wxPoint(594, 500), wxSize(32, 32), 0, wxString("CoinImg"));
	healthPotionIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "health_potion.png"), wxBITMAP_TYPE_PNG), wxPoint(678, 500), wxSize(32, 32), 0, wxString("HPImg"));;

	// Armor and Weapon
	armorIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "no_armor.png"), wxBITMAP_TYPE_PNG), wxPoint(520, 10), wxSize(121, 388), 0, wxString("ArmorImg"));
	weaponIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + "no_armor.png"), wxBITMAP_TYPE_PNG), wxPoint(650, 10), wxSize(64, 64), 0, wxString("WeaponImg"));
	
	// Inits text to be displayed
	coinCountText = new wxStaticText(this, wxID_ANY, wxString("x0"), wxPoint(626, 510), wxSize(12, 12));
	coinCountText->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	
	heartCountText = new wxStaticText(this, wxID_ANY, wxString("x0"), wxPoint(542, 510), wxSize(12, 12));
	heartCountText->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	healthPotionCountText = new wxStaticText(this, wxID_ANY, wxString("x0"), wxPoint(710, 510), wxSize(12, 12));
	healthPotionCountText->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	
	inputRecieved = false;
}

cMain::~cMain() {
    delete m_bt1;
	delete m_output;
    delete m_input;
	delete heartIcon;
	delete armorIcon;
	delete weaponIcon;
	delete healthPotionIcon;
	delete coinCountText;
	delete heartCountText;
	delete healthPotionCountText;
	delete m_pThread;
}

void cMain::setArmorIcon(std::string armorChoiceFileName) {
	if (armorIcon != nullptr) {
		delete armorIcon;
	}

	armorIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + armorChoiceFileName), wxBITMAP_TYPE_PNG), wxPoint(520, 10), wxSize(121, 388), 0, wxString("ArmorImg"));
}

void cMain::setWeaponIcon(std::string weaponChoiceFileName) {
	if (weaponIcon != nullptr) {
		delete weaponIcon;
	}

	weaponIcon = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxString(assetsPath + weaponChoiceFileName), wxBITMAP_TYPE_PNG), wxPoint(650, 10), wxSize(64, 64), 0, wxString("WeaponImg"));
}

void cMain::updateCoins(int coins) {
	coinCountText->SetLabel(wxString("x"+std::to_string(coins)));
}

void cMain::updateHeart(int hearts) {
	heartCountText->SetLabel(wxString("x" + std::to_string(hearts)));
}

void cMain::updateHealthPotions(int health_potions) {
	healthPotionCountText->SetLabel(wxString("x" + std::to_string(health_potions)));
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

void cMain::OnClose(wxCloseEvent& event)
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
// have client point to abstract factory
// have something different in each Armor and Weapons

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

void cMain::OnStopThread(wxCommandEvent& event) {

	StopThread();
}

void cMain::OnQuit(wxCommandEvent& WXUNUSED(event))
{

	// true is to force the frame to close
	Close(true);
}



