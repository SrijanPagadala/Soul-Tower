#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "CharacterType.hpp"
#include "CharacterTypeFactory.hpp"
#include "Bow.hpp"
#include "Leather.hpp"
#include "Archer.hpp"

using namespace std;

class ArcherFactory : public ChracterTypeFactory {
public:
	virtual Weapon* createWeapon() {
		Weapon* weapon = new Bow();
		return weapon;
	}
	virtual Armor* createArmor() {
		Armor* armor = new Leather();
		return armor;
	
	}
	virtual CharacterType* createCharacter() {
		CharacterType* character = new Archer();
		return character;
	}
};