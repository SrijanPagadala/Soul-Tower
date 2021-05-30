#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "CharacterType.hpp"
#include "cMain.h"
using namespace std;

class CharacterTypeFactory {
protected:
	cMain* gui;
public:
	CharacterTypeFactory(cMain* gui) {
		this->gui = gui;
	};
	virtual Weapon* createWeapon() = 0;
	virtual Armor* createArmor() = 0;
	virtual CharacterType* createCharacter() = 0;
};
