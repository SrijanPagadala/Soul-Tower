#pragma once
#include "Enemy.hpp"

class ArcherGoblin : public Enemy
{
	public:
		ArcherGoblin(std::string name) : Enemy(name){
		
		}

		virtual void attack(Archer* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
		}
		virtual void attack(Warrior* player) {
			double damageTotal = baseDamage * 0.8;
			player->takeDamage(baseDamage);
		}
		virtual void attack(Mage* player) {
			double damageTotal = baseDamage * 2;
			player->takeDamage(baseDamage);
		}

};