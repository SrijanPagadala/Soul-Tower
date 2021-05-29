#pragma once

class Enemy
{

	protected:
		double health;
		const double maxHealth = 100;
		double baseDamage = 15;

	public:
		void takeDamage(double damage);
		bool isAlive();

};
