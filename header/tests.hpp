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
	delete gui;
	gui = nullptr;
}

void CreateArcherWeapon() {
	cMain* gui = new cMain();
	ArcherFactory factory(gui);
	Weapon* ptr = nullptr;
	ptr = factory.createWeapon();
	if (ptr != nullptr) {
		cout << "CreateArcherWeapon [PASSED]" << endl;
	}
	else {
		cout << "CreateArcherWeapon [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateArcherCharacter() {
	cMain* gui = new cMain();
	ArcherFactory factory(gui);
	CharacterType* ptr = nullptr;
	ptr = factory.createCharacter();
	if (ptr != nullptr) {
		cout << "CreateArcherCharacter [PASSED]" << endl;
	}
	else {
		cout << "CreateArcherCharacter [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateWarriorArmor() {
	cMain* gui = new cMain();
	WarriorFactory factory(gui);
	Armor* ptr = nullptr;
	ptr = factory.createArmor();
	if (ptr != nullptr) {
		cout << "CreateWarriorArmor [PASSED]" << endl;
	}
	else {
		cout << "CreateWarriorArmor [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateWarriorWeapon() {
	cMain* gui = new cMain();
	WarriorFactory factory(gui);
	Weapon* ptr = nullptr;
	ptr = factory.createWeapon();
	if (ptr != nullptr) {
		cout << "CreateWarriorWeapon [PASSED]" << endl;
	}
	else {
		cout << "CreateWarriorWeapon [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateWarriorCharacter() {
	cMain* gui = new cMain();
	WarriorFactory factory(gui);
	CharacterType* ptr = nullptr;
	ptr = factory.createCharacter();
	if (ptr != nullptr) {
		cout << "CreateWarriorCharacter [PASSED]" << endl;
	}
	else {
		cout << "CreateWarriorCharacter [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateMageArmor() {
	cMain* gui = new cMain();
	MageFactory factory(gui);
	Armor* ptr = nullptr;
	ptr = factory.createArmor();
	if (ptr != nullptr) {
		cout << "CreateMageArmor [PASSED]" << endl;
	}
	else {
		cout << "CreateMageArmor [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateMageWeapon() {
	cMain* gui = new cMain();
	MageFactory factory(gui);
	Weapon* ptr = nullptr;
	ptr = factory.createWeapon();
	if (ptr != nullptr) {
		cout << "CreateMageWeapon [PASSED]" << endl;
	}
	else {
		cout << "CreateMageWeapon [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void CreateMageCharacter() {
	cMain* gui = new cMain();
	MageFactory factory(gui);
	CharacterType* ptr = nullptr;
	ptr = factory.createCharacter();
	if (ptr != nullptr) {
		cout << "CreateMageCharacter [PASSED]" << endl;
	}
	else {
		cout << "CreateMageCharacter [FAILED]" << endl;
	}
	delete gui;
	gui = nullptr;
}

void ArcherVSWarriorGoblin() {
	cMain* gui = new cMain();
	ArcherFactory factory(gui);
	CharacterType* player = factory.createCharacter();
	Armor* armorptr = factory.createArmor();
	Weapon* weaponptr = factory.createWeapon();
	player->setArmor(armorptr);
	player->setWeapon(weaponptr);
	WarriorGoblin* enemy = new WarriorGoblin("test");
	double resultToTest = player->takeDamage(enemy, 100);
	if (resultToTest == 135) {
		cout << "ArcherVSWarriorGoblin [PASSED]" << endl;
	}
	else {
		cout << "ArcherVSWarriorGoblin [FAILED]" << endl;
	}
	delete player;
	player = nullptr;
	delete enemy;
	enemy = nullptr;
}

void runTests() {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);


	cout << "--------------WARRIOR TESTS--------------" << endl;




	cout << "--------------WARRIOR TESTS--------------" << endl << endl;


	cout << "--------------ARCHER TESTS--------------" << endl;




	cout << "--------------ARCHER TESTS--------------" << endl << endl;
	ArcherVSWarriorGoblin();


	cout << "--------------MAGE TESTS--------------" << endl;




	cout << "--------------MAGE TESTS--------------" << endl << endl;


	cout << "--------------SWORD TESTS--------------" << endl;




	cout << "--------------SWORD TESTS--------------" << endl << endl;


	cout << "--------------WAND TESTS--------------" << endl;




	cout << "--------------WAND TESTS--------------" << endl << endl;


	cout << "--------------BOW TESTS--------------" << endl;




	cout << "--------------BOW TESTS--------------" << endl << endl;

	cout << "--------------MAGE FACTORY TESTS--------------" << endl;
	CreateMageArmor();
	CreateMageWeapon();
	CreateMageCharacter();

	cout << "--------------MAGE FACTORY TESTS--------------" << endl << endl;

	cout << "--------------ARCHER FACTORY TESTS--------------" << endl;
	CreateArcherArmor();
	CreateArcherWeapon();
	CreateArcherCharacter();



	cout << "--------------ARCHER FACTORY TESTS--------------" << endl << endl;

	cout << "--------------WARRIOR FACTORY TESTS--------------" << endl;
	CreateWarriorArmor();
	CreateWarriorWeapon();
	CreateWarriorCharacter();



	cout << "--------------WARRIOR FACTORY TESTS--------------" << endl << endl;

	cout << "--------------GAME TESTS--------------" << endl;
	InitializedCoins();
	NegativeCoins();
	SetCoins();
	cout << "--------------GAME TESTS--------------" << endl << endl; 
}