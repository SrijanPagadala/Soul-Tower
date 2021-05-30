#pragma once
#include "Enemy.hpp"


class WarriorGoblin: public Enemy
{
	public:
		WarriorGoblin(std::string name) : Enemy(name) {

		}
		
		virtual double attack(CharacterType* player) {
			double damageTotal = player->takeDamage(this, baseDamage);
			return damageTotal;
		}
		
		virtual void attackOutput(cMain* gui) {
			gui->DisplayOut(name + " slashed you! \n");
		}

};

