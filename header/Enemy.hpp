#pragma once
#include "cMain.h"
#include "Archer.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include <string>

class Enemy
{
	protected:
		double health;
		const double maxHealth = 100;
		double baseDamage;
		std::string name;

	public:
		Enemy(string name): name(name), health(maxHealth), baseDamage(15){

		}

		void takeDamage(double damage);
		bool isAlive();
		
		std::string getName() {
			return name;
		}

		virtual void attack(Archer* player) = 0;
		virtual void attack(Warrior* player) = 0;
		virtual void attack(Mage* player) = 0;
		virtual void attackOutput(cMain* gui) = 0;

};
