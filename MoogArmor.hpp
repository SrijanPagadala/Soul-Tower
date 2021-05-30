#pragma once
#include "Armor.hpp"
class MoogArmor : public Armor
{
	MoogArmor() {

	}

	virtual void update(cMain* gui) {
		if (tier > 1) {
			gui->setArmorIcon("warrior_diamond_armor.png");
		}
	}
};
