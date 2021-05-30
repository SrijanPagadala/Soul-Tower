#pragma once
#include "Enemy.hpp"


class WarriorGoblin: public Enemy
{
	public:
		WarriorGoblin(std::string name) : Enemy(name) {

		}

		virtual double attack(Archer* player) {
			double damageTotal = baseDamage * 1.2;
			player->takeDamage(baseDamage);
			return damageTotal;
		}
		virtual double attack(Warrior* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
			return damageTotal;
		}
		virtual double attack(Mage* player) {
			double damageTotal = baseDamage * 1.5;
			player->takeDamage(baseDamage);
			return damageTotal;
		}

		virtual double attack(CharacterType* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
			return damageTotal;
		}

		virtual void attackOutput(cMain* gui) {
			gui->DisplayOut(name + " slashed you! \n");
		}

};

