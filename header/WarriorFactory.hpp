#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "CharacterType.hpp"
#include "CharacterTypeFactory.hpp"
#include "Sword.hpp"
#include "Chain.hpp"
#include "Warrior.hpp"

using namespace std;

class WarriorFactory : public CharacterTypeFactory {
public:
	WarriorFactory(cMain* gui) : CharacterTypeFactory(gui) {

	}
	virtual Weapon* createWeapon() {
		Weapon* weapon = new Sword();
		return weapon;
	}
	virtual Armor* createArmor() {
		Armor* armor = new Chain();
		return armor;

	}
	virtual CharacterType* createCharacter() {
		CharacterType* character = new Warrior(gui);
		return character;
	}
};
