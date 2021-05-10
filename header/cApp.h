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

