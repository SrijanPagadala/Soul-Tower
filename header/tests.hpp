#pragma once
#include <iostream>
#include "../header/Mage.hpp"
#include "../header/Warrior.hpp"
#include "../header/Archer.hpp"
#include "../header/MageFactory.hpp"
#include "../header/ArcherFactory.hpp"
#include "../header/WarriorFactory.hpp"
#include "../header/Sword.hpp"
#include "../header/Wand.hpp"
#include "../header/Bow.hpp"
#include "../header/cMain.h"
#include "../header/Weapon.hpp"
#include "../header/Armor.hpp"


using namespace std;
void InitializedCoins() {
	cMain* gui = new cMain();
	Game game(gui);
	if (game.getCoins() == 0) { //GAME TEST 1: Check initialized coins
		cout << "InitializedCoins [PASSED]" << endl;
	}
	else {
		cout << "InitializedCoins [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void NegativeCoins() {
	cMain* gui = new cMain();
	Game game(gui);
	game.changeCoins(-100000);
	if (game.getCoins() == 0) { //GAME TEST 2: Check to make sure coins can't be negative
		cout << "NegativeCoins [PASSED]" << endl;
	}
	else {
		cout << "NegativeCoins [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void SetCoins() {
	cMain* gui = new cMain();
	Game game(gui);
	game.setCoins(100);
	if (game.getCoins() == 100) {
		cout << "SetCoins [PASSED]" << endl;
	}
	else {
		cout << "SetCoins [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateArcherArmor() {
	cMain* gui = new cMain();
	ArcherFactory factory(gui);
	Armor* ptr = nullptr;
	ptr = factory.createArmor();
	if (ptr != nullptr) {
		cout << "CreateArcherArmor [PASSED]" << endl;
	}
	else {
		cout << "CreateArcherArmor [FAILED]" << endl;
	}
}


void runTests() {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);


	cout << "--------------WARRIOR TESTS--------------" << endl;




	cout << "--------------WARRIOR TESTS--------------" << endl << endl;


	cout << "--------------ARCHER TESTS--------------" << endl;




	cout << "--------------ARCHER TESTS--------------" << endl << endl;


	cout << "--------------MAGE TESTS--------------" << endl;




	cout << "--------------MAGE TESTS--------------" << endl << endl;


	cout << "--------------SWORD TESTS--------------" << endl;




	cout << "--------------SWORD TESTS--------------" << endl << endl;


	cout << "--------------WAND TESTS--------------" << endl;




	cout << "--------------WAND TESTS--------------" << endl << endl;


	cout << "--------------BOW TESTS--------------" << endl;




	cout << "--------------BOW TESTS--------------" << endl << endl;

	cout << "--------------MAGE FACTORY TESTS--------------" << endl;




	cout << "--------------MAGE FACTORY TESTS--------------" << endl << endl;


	cout << "--------------ARCHER FACTOR TESTS--------------" << endl;




	cout << "--------------ARCHER FACTORY TESTS--------------" << endl << endl;

	cout << "--------------WARRIOR FACTORY TESTS--------------" << endl;




	cout << "--------------WARRIOR FACTORY TESTS--------------" << endl << endl;

	cout << "--------------GAME TESTS--------------" << endl;
	InitializedCoins();

	cout << "--------------GAME TESTS--------------" << endl << endl; 
}