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

		virtual double takeDamage(Sword*, double baseDamage) {
			double damageDealt = baseDamage * 1;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

		virtual double takeDamage(Wand*, double baseDamage) {
			double damageDealt = baseDamage * 2;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

		virtual double takeDamage(Bow*, double baseDamage) {
			double damageDealt = baseDamage * 0.8;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

};

