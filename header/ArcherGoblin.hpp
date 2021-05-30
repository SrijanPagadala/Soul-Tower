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

		virtual double takeDamage(Sword*, double baseDamage) {
			double damageDealt = baseDamage * 1.5;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

		virtual double takeDamage(Wand*, double baseDamage) {
			double damageDealt = baseDamage * 1.25;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

		virtual double takeDamage(Bow*, double baseDamage) {
			double damageDealt = baseDamage * 1;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

};