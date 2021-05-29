#pragma once
#include "Enemy.hpp"


class MageGoblin : public Enemy
{
	public:
		MageGoblin(): Enemy() {
		
		}

		virtual void attack(Archer* player) {
			double damageTotal = baseDamage * 1.2;
			player->takeDamage(baseDamage);
		}

		virtual void attack(Warrior* player) {
			double damageTotal = baseDamage * 1.5;
			player->takeDamage(baseDamage);
		}
		virtual void attack(Mage* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
		}

};