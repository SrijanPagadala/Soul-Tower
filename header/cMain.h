#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
	private:
		wxButton* m_bt1;
		wxTextCtrl* m_input;
		wxTextCtrl* m_output;
		wxString input_choice;
		bool inputRecieved;
	public:
		wxString GetChoice();
		void SubmitChoice(wxCommandEvent& event);
		cMain();
		~cMain();
		DECLARE_EVENT_TABLE()
};

