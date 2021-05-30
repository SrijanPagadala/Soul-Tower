#pragma once
#pragma once
#include "Armor.hpp"
class AkilsArmor : public Armor
{
	public:
		AkilsArmor(cMain* gui) : Armor(gui) {

		}

		virtual void update(cMain* gui) {
			if (tier > 1) {
				gui->setArmorIcon("archer_iron_armor.png");
			}
		}
};