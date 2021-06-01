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

//////////////////////SWORD//////////////////////

void weaponInitSword() {
	Sword sword;
	if (sword.getAttackDamage() == 20, sword.getTier() == 1) {
		cout << "WeaponInitSword [PASSED]" << endl;
	}
	else {
		cout << "WeaponInitSword [FAILED]" << endl;
	}
}


void swordAttackWarriorGoblin() {
	Enemy* enemy = new WarriorGoblin("enemy");
	Sword weapon;

	if (weapon.attack(enemy) == 20) {
		cout << "SwordAttackWarriorGoblin [PASSED]" << endl;
	}

	else {
		cout << "SwordAttackWarriorGoblin [FAILED]" << endl;
	}
}

void swordAttackMageGoblin() {
	Enemy* enemy = new MageGoblin("enemy");
	Sword weapon;


	if (weapon.attack(enemy) == 40) {
		cout << "SwordAttackMageGoblin [PASSED]" << endl;
	}

	else {
		cout << "SwordAttackMageGoblin [FAILED]" << endl;
	}
}

void swordAttackArcherGoblin() {
	Enemy* enemy = new ArcherGoblin("enemy");
	Sword weapon;

	if (weapon.attack(enemy) == 30) {
		cout << "SwordAttackArcherGoblin [PASSED]" << endl;
	}

	else {
		cout << "SwordAttackArcherGoblin [FAILED]" << endl;
	}
}

//////////////////////SWORD//////////////////////


///////////////////////BOW///////////////////////


void weaponInitBow() {
	Bow weapon;
	if (weapon.getAttackDamage() == 20, weapon.getTier() == 1) {
		cout << "WeaponInitSword [PASSED]" << endl;
	}
	else {
		cout << "WeaponInitSword [FAILED]" << endl;
	}
}

void bowAttackWarriorGoblin() {
	Enemy* enemy = new WarriorGoblin("enemy");
	Bow weapon;

	if (weapon.attack(enemy) == 16) {
		cout << "BowAttackWarriorGoblin [PASSED]" << endl;
	}

	else {
		cout << "BowAttackWarriorGoblin [FAILED]" << endl;
	}
}

void bowAttackMageGoblin() {
	Enemy* enemy = new MageGoblin("enemy");
	Bow weapon;


	if (weapon.attack(enemy) == 25) {
		cout << "BowAttackMageGoblin [PASSED]" << endl;
	}

	else {
		cout << "BowAttackMageGoblin [FAILED]" << endl;
	}
}

void bowAttackArcherGoblin() {
	Enemy* enemy = new ArcherGoblin("enemy");
	Bow weapon;

	if (weapon.attack(enemy) == 20) {
		cout << "BowAttackArcherGoblin [PASSED]" << endl;
	}

	else {
		cout << "BowAttackArcherGoblin [FAILED]" << endl;
	}
}

///////////////////////BOW///////////////////////

//////////////////////WAND///////////////////////

void weaponInitWand() {
	Wand weapon;
	if (weapon.getAttackDamage() == 20, weapon.getTier() == 1) {
		cout << "WeaponInitSword [PASSED]" << endl;
	}
	else {
		cout << "WeaponInitSword [FAILED]" << endl;
	}
}

void wandAttackWarriorGoblin() {
	Enemy* enemy = new WarriorGoblin("enemy");
	Wand weapon;

	if (weapon.attack(enemy) == 40) {
		cout << "WandAttackWarriorGoblin [PASSED]" << endl;
	}

	else {
		cout << "WandAttackWarriorGoblin [FAILED]" << endl;
	}
}

void wandAttackMageGoblin() {
	Enemy* enemy = new MageGoblin("enemy");
	Wand weapon;

	if (weapon.attack(enemy) == 20) {
		cout << "WandAttackMageGoblin [PASSED]" << endl;
	}

	else {
		cout << "WandAttackMageGoblin [FAILED]" << endl;
	}
}

void wandAttackArcherGoblin() {
	Enemy* enemy = new ArcherGoblin("enemy");
	Wand weapon;

	if (weapon.attack(enemy) == 25) {
		cout << "WandAttackArcherGoblin [PASSED]" << endl;
	}

	else {
		cout << "WandAttackArcherGoblin [FAILED]" << endl;
	}
}


//////////////////////WAND///////////////////////




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
	weaponInitSword();
	swordAttackWarriorGoblin();
	swordAttackMageGoblin();
	swordAttackArcherGoblin();
	cout << "--------------SWORD TESTS--------------" << endl << endl;

	cout << "--------------WAND TESTS--------------" << endl;
	weaponInitWand();
	wandAttackWarriorGoblin();
	wandAttackMageGoblin();
	wandAttackArcherGoblin();
	cout << "--------------WAND TESTS--------------" << endl << endl;

	cout << "--------------BOW TESTS--------------" << endl;
	weaponInitBow();
	bowAttackWarriorGoblin();
	bowAttackMageGoblin();
	bowAttackArcherGoblin();
	cout << "--------------BOW TESTS--------------" << endl << endl;

	cout << "--------------MAGE FACTORY TESTS--------------" << endl;
	cout << "--------------MAGE FACTORY TESTS--------------" << endl << endl;

	cout << "--------------ARCHER FACTOR TESTS--------------" << endl;
	cout << "--------------ARCHER FACTORY TESTS--------------" << endl << endl;

	cout << "--------------WARRIOR FACTORY TESTS--------------" << endl;
	cout << "--------------WARRIOR FACTORY TESTS--------------" << endl << endl;

	cout << "--------------GAME TESTS--------------" << endl;
	cout << "--------------GAME TESTS--------------" << endl << endl;

}