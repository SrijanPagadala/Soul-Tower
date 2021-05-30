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

};
#endif