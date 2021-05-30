#ifndef __MAGE_GOLBIN__H
#define	__MAGE_GOLBIN__H
#include "Enemy.hpp"


class MageGoblin : public Enemy
{
	public:
		MageGoblin(std::string name) : Enemy(name) {
		
		}

		virtual double attack(CharacterType* player) {
			double damageTotal = player->takeDamage(this, baseDamage);
			return damageTotal;
		}

		virtual void attackOutput(cMain* gui) {
			gui->DisplayOut(name + " attacked you with a spell! \n");
		}

		virtual double takeDamage(Sword*, double baseDamage) {
			double damageDealt = baseDamage * 2;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

		virtual double takeDamage(Wand*, double baseDamage) {
			double damageDealt = baseDamage * 1;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

		virtual double takeDamage(Bow*, double baseDamage) {
			double damageDealt = baseDamage * 1.25;
			Enemy::takeDamage(damageDealt);
			return damageDealt;
		};

};
#endif