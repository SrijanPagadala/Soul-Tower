#pragma once
#include "Enemy.hpp"
#include "Archer.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"

class WarriorGoblin: public Enemy
{
	public:
		void attack(Archer* player) {
			double damageTotal = baseDamage * 1.2;
			player->takeDamage(baseDamage);
		}
		void attack(Warrior* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
		}
		void attack(Mage* player) {
			double damageTotal = baseDamage * 1.5;
			player->takeDamage(baseDamage);
		}

};

