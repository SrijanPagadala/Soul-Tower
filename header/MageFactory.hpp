#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "CharacterType.hpp"
#include "CharacterTypeFactory.hpp"
#include "Wand.hpp"
#include "Robes.hpp"
#include "Mage.hpp"

using namespace std;

class MageFactory : public ChracterTypeFactory {
public:
	virtual Weapon* createWeapon() {
		Weapon* weapon = new Wand();
		return weapon;
	}
	virtual Armor* createArmor() {
		Armor* armor = new Robes();
		return armor;

	}
	virtual CharacterType* createCharacter() {
		CharacterType* character = new Mage();
		return character;
	}
};
