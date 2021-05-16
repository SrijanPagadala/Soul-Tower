#pragma once
#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp
{
	private:
		cMain* m_frame_1 = nullptr;
	public:
		cApp();
		~cApp();
		virtual bool OnInit();
};

enum {
	BUTTON_Choicse = wxID_HIGHEST + 1,
	TEXTBOX_Outputss = wxID_HIGHEST + 2
};

