#pragma once
#include "Enemy.hpp"

class ArcherGoblin : public Enemy
{
	public:
		ArcherGoblin(std::string name) : Enemy(name){
		
		}

		virtual double attack(Archer* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
			return damageTotal;
		}
		virtual double attack(Warrior* player) {
			double damageTotal = baseDamage * 0.8;
			player->takeDamage(baseDamage);
			return damageTotal;
		}
		virtual double attack(Mage* player) {
			double damageTotal = baseDamage * 2;
			player->takeDamage(baseDamage);
			return damageTotal;
		}

		virtual double attack(CharacterType* player) {
			double damageTotal = baseDamage * 1;
			player->takeDamage(baseDamage);
			return damageTotal;
		}

		virtual void attackOutput(cMain* gui) {
			gui->DisplayOut(name + " shot at you! \n");
		}

};