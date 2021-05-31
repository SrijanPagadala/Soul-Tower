#pragma once

#include "Weapon.hpp"
#include "Armor.hpp"
#include "CharacterType.hpp"
#include "CharacterTypeFactory.hpp"
#include "Wand.hpp"
#include "MoogArmor.hpp"
#include "Mage.hpp"

using namespace std;

class MageFactory : public CharacterTypeFactory {
	public:
		MageFactory(cMain* gui) : CharacterTypeFactory(gui) {

		}
		virtual Weapon* createWeapon() {
			Weapon* weapon = new Wand();
			return weapon;
		}
		virtual Armor* createArmor() {
			Armor* armor = new MoogArmor(gui);
			return armor;

		}
		virtual CharacterType* createCharacter() {
			CharacterType* character = new Mage(gui);
			return character;
		}
};
