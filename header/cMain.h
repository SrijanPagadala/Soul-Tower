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

};

class cMain : public wxFrame
{
	private:
		wxButton* m_bt1;
		wxTextCtrl* m_input;
		wxTextCtrl* m_output;
		wxString input_choice;
		bool inputRecieved;
		DECLARE_EVENT_TABLE();
		
	public:
		Game* m_pThread;
		wxCriticalSection m_pThreadCS;


		cMain();
		~cMain();
		wxString GetChoice();
		void SubmitChoice(wxCommandEvent& event);
		void DisplayOutput(std::string msg);
		
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void OnStartThread(wxCommandEvent& event);
		void OnStopThread(wxCommandEvent& event);

		void OnThreadUpdate(wxThreadEvent&);
		void OnThreadCompletion(wxThreadEvent&);
		void OnClose(wxCloseEvent&);

		void StopThread();

};

// IDs for the controls and the menu commands
enum
{
	// menu items
	Minimal_Quit = wxID_EXIT,

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	Minimal_About = wxID_ABOUT,

	MYTHREAD_UPDATE = wxID_HIGHEST + 1,
	MYTHREAD_COMPLETED,
	THREAD_START,
	THREAD_STOP,

	BUTTON_Choice = wxID_HIGHEST + 1,
	TEXTBOX_Output = wxID_HIGHEST + 2
};

