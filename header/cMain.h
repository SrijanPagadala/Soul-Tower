#pragma once
#include "wx/wx.h"
#include "State.hpp"

class cMain;

class Game : public wxThread
{
	protected:
		cMain* gui;
		double coins;
        int healthPotions;
        State* currState;
		virtual wxThread::ExitCode Entry();

	public:
		Game(cMain* gui) : wxThread(wxTHREAD_DETACHED) {
			this->gui = gui;
			coins = 0;
			healthPotions = 0;
			currState = nullptr;
		};

		~Game()
		{

		};

		double getCoins() { return coins; }
        void setCoins(double newAmount) { coins = newAmount; }
        void changeCoins(double amount) { coins += amount; }

        int getPotions() { return healthPotions; }
        void setPotions(double newAmount) { healthPotions = newAmount; }
        void changePotions(double amount) { healthPotions += amount; }

		void start();

};

class cMain : public wxFrame
{
	private:

		std::string assetsPath = "C:/Users/duoma/Desktop/Projects/final-project-ssond007-_nkhal016_spaga006/assets/";
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
	TEXTBOX_Output = wxID_HIGHEST + 2
};

