#ifndef ENEMY_H
#define ENEMY_H
#include "cMain.h"
#include "Archer.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "CharacterType.hpp"
#include <string>

class Enemy
{
	protected:
		const double maxHealth = 100;
		double health = maxHealth;
		double baseDamage;
		std::string name;

	public:
		Enemy(std::string name): name(name), health(maxHealth), baseDamage(15){

		}

		void takeDamage(double damage);
		bool isAlive();
		double getHealth();
		
		std::string getName() {
			return name;
		}
		

		//virtual double attack(Archer* player) = 0;
		//virtual double attack(Warrior* player) = 0;
		//virtual double attack(Mage* player) = 0;
		virtual double attack(CharacterType* player) = 0;
		virtual void attackOutput(cMain* gui) = 0;

		virtual double takeDamage(Sword*, double baseDamage) = 0;
		virtual double takeDamage(Wand*, double baseDamage) = 0;
		virtual double takeDamage(Bow*, double baseDamage) = 0;

};

#endif
