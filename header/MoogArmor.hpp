#pragma once
#include "Armor.hpp"
class MoogArmor : public Armor
{
	public:
		MoogArmor(cMain* gui): Armor(gui) {

		}

		virtual void update(cMain* gui) {
			if (tier > 1) {
				gui->setArmorIcon("mage_golden_armor.png");
			}
		}
};
