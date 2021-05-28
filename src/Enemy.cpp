#include "Enemy.hpp"


void Enemy::takeDamage(double damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}