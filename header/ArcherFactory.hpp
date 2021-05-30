#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "CharacterType.hpp"
#include "CharacterTypeFactory.hpp"
#include "Bow.hpp"
#include "AkilsArmor.hpp"
#include "Archer.hpp"

using namespace std;

class ArcherFactory : public CharacterTypeFactory {
public:
	ArcherFactory(cMain* gui): CharacterTypeFactory(gui){

	}
	virtual Weapon* createWeapon() {
		Weapon* weapon = new Bow();
		return weapon;
	}
	virtual Armor* createArmor() {
		Armor* armor = new AkilsArmor(gui);
		return armor;
	
	}
	virtual CharacterType* createCharacter() {
		CharacterType* character = new Archer(gui);
		return character;
	}
};