#include "../header/Enemy.hpp"


void Enemy::takeDamage(double damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

double Enemy::getHealth() {
	return health;
}

bool Enemy::isAlive() {
	return health > 0;
}