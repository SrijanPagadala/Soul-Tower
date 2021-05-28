#pragma once

class Enemy
{

	protected:
		double health;
		const double maxHealth = 100;
		double baseDamage;

	public:
		void takeDamage(double damage);
};
