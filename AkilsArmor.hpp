#pragma once
#pragma once
#include "Armor.hpp"
class AkilsArmor : public Armor
{
	AkilsArmor() {

	}

	virtual void update(cMain* gui) {
		if (tier > 1) {
			gui->setArmorIcon("archer_leather_armor.png");
		}
	}
};