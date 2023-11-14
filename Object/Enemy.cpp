#include "Enemy.h"

void Enemy::Initialize()
{
	inputManager_ = InputManager::GetInstance();
	enemy = {500, 100, 30}; 
	isAlive = true;
}

void Enemy::Update() 
{
	
}

void Enemy::Draw() 
{
	if (isAlive == true) {
		Novice::DrawEllipse(
		    static_cast<int>(enemy.position.x), static_cast<int>(enemy.position.y),
		    static_cast<int>(enemy.radius), static_cast<int>(enemy.radius), 0.0f, RED,
		    kFillModeSolid);
	}
}

Object Enemy::GetEnemy() 
{
	Object result;
	result = enemy;
	return result;
}

void Enemy::SetAlive(bool Alive) 
{ 
	isAlive = Alive;
}

