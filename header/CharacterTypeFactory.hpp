#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "CharacterType.hpp"

using namespace std;

class CharacterTypeFactory {
public:
	virtual Weapon* createWeapon() = 0;
	virtual Armor* createArmor() = 0;
	virtual CharacterType* createCharacter() = 0;
};
