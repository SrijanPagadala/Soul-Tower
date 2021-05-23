#pragma once
#include "wx/wx.h"

class cMain;

class Game : public wxThread
{
	protected:
		cMain* gui;
		virtual wxThread::ExitCode Entry();

	public:
		Game(cMain* gui) : wxThread(wxTHREAD_DETACHED) {
			this->gui = gui;
		};

		~Game()
		{

		};
		// Now is switched back so i have access to cMain.h
		void start();

};

class cMain : public wxFrame
{
	private:
		// Armor Icons
		std::string assetsPath = "C:/Users/duoma/Desktop/Projects/final-project-ssond007-_nkhal016_spaga006/assets/";
		// *** Armor Types File Names **
		// warriorCopperArmor = "warrior_diamond_armor.png";
		// warriorDiamondArmor = "warrior_copper_armor.png";
		// archerIronArmor = "archer_iron_armor.png";
		// archerLeatherArmor = "archer_leather_armor.png";
		// mageAmethystArmor = "mage_amethyst_armor.png";
		// mageGoldenArmor = "mage_golden_armor.png";

		// Menu Objs
		wxButton* m_bt1;
		wxTextCtrl* m_input;
		wxTextCtrl* m_output;
		wxString input_choice;
		wxStaticBitmap* heartIcon;
		wxStaticBitmap* coinIcon;
		wxStaticBitmap* armorIcon;
		bool inputRecieved;
		DECLARE_EVENT_TABLE();
		
	public:
		Game* m_pThread;
		wxCriticalSection m_pThreadCS;
		// Constructor & Deconstructor
		cMain();
		~cMain();
		// Methods
		std::string GetChoice();
		void setArmorIcon(std::string armorChoiceFileName);
		void SubmitChoice(wxCommandEvent& event);
		void DisplayOutput(std::string msg);
		void OnQuit(wxCommandEvent& event);
		void OnStartThread();
		void OnClose(wxCloseEvent&);
		void StopThread();

};

// IDs for the controls and the menu commands
enum
{
	// menu items
	Minimal_Quit = wxID_EXIT,

	Minimal_About = wxID_ABOUT,

	MYTHREAD_UPDATE = wxID_HIGHEST + 1,
	MYTHREAD_COMPLETED,
	THREAD_START,
	THREAD_STOP,

	BUTTON_Choice = wxID_HIGHEST + 1,
	TEXTBOX_Output = wxID_HIGHEST + 2,

};

