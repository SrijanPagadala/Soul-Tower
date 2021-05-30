#pragma once
#include "Enemy.hpp"


class MageGoblin : public Enemy
{
	public:
		MageGoblin(std::string name) : Enemy(name) {
		
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

		virtual void attackOutput(cMain* gui) {
			gui->DisplayOut(name + " attacked you with a spell!");
		}

};