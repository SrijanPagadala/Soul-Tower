#pragma once
#include "Enemy.hpp"

class ArcherGoblin : public Enemy
{
	public:
		ArcherGoblin(std::string name) : Enemy(name){
		
		}

		virtual double attack(CharacterType* player) {
			double damageTotal = player->takeDamage(this, baseDamage);
			return damageTotal;
		}

		virtual void attackOutput(cMain* gui) {
			gui->DisplayOut(name + " shot at you! \n");
		}

};