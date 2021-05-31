#pragma once
#include "wx/wx.h"
#include <iostream>
#include <string>
using namespace std;

class CharacterType;
class Enemy;
class cMain;
class State;

class Game : public wxThread
{
	protected:
		cMain* gui;
		double coins;
        int healthPotions;
		State* currState;
		Enemy* enemy;
		CharacterType* player;
		int MaxLevel;

		virtual wxThread::ExitCode Entry();

	public:
		Game(cMain* gui) : wxThread(wxTHREAD_DETACHED) {
			this->gui = gui;
			coins = 0;
			healthPotions = 0;
			currState = nullptr;
			player = nullptr;
			MaxLevel = 3;
		};

		~Game();

		// Now is switched back so i have access to cMain.h
		bool gameOver = false;

		double getCoins();
		void setCoins(double newAmount);
		void changeCoins(double amount);

		int getPotions();
		void setPotions(double newAmount);
		void changePotions(double amount);

		Enemy* getEnemy() {
			return enemy;
		}

		void setEnemy(Enemy* enemy) {
			this->enemy = enemy;
		}

		CharacterType* getPlayer() {
			return player;
		}



		// Gameplay methods
		void classSelection();
		void start();

};

class cMain : public wxFrame
{
	private:
		// Armor Icons
		std::string assetsPath = "C:/Users/PC/source/repos/FinalProjectCS100/assets/";
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
		wxStaticBitmap* weaponIcon;
		wxStaticBitmap* healthPotionIcon;
		// Text Objs
		wxStaticText* coinCountText;
		wxStaticText* heartCountText;
		wxStaticText* healthPotionCountText;
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
		void setWeaponIcon(std::string armorChoiceFileName);
		void SubmitChoice(wxCommandEvent& event);
		void DisplayOut(std::string msg);
		void OnQuit(wxCommandEvent& event);
		void OnStartThread();
		void OnClose(wxCloseEvent&);
		void OnStopThread(wxCommandEvent& event);
		void StopThread();

		void updateCoins(int coins);
		void updateHeart(int hearts);
		void updateHealthPotions(int health_potions);
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


