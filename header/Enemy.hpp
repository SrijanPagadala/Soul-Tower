#pragma once
#include "Archer.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"

class Enemy
{
	protected:
		double health;
		const double maxHealth = 100;
		double baseDamage;

	public:
		Enemy(): health(maxHealth), baseDamage(15){

		}

		void takeDamage(double damage);
		bool isAlive();
		virtual void attack(Archer* player) = 0;
		virtual void attack(Warrior* player) = 0;
		virtual void attack(Mage* player) = 0;

};
