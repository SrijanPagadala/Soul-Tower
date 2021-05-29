#pragma once
#include "Enemy.hpp"

class Archer;
class Warrior;
class Mage;

class ArcherGoblin : public Enemy
{
	public:
		void attack(Archer* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
		}
		void attack(Warrior* player) {
			double damageTotal = baseDamage * 0.8;
			player->takeDamage(baseDamage);
		}
		void attack(Mage* player) {
			double damageTotal = baseDamage * 2;
			player->takeDamage(baseDamage);
		}

};