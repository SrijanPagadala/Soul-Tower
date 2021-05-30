#pragma once
#include "Armor.hpp"
class WarmogsArmor : public Armor 
{
	public:
		WarmogsArmor(cMain* gui) : Armor(gui)) {
		
		}

		virtual void update(cMain* gui) {
			if (tier > 1) {
				gui->setArmorIcon("warrior_diamond_armor.png");
			}
		}
};
