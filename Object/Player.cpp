#include "Player.h"

void Player::Initialize() 
{
	inputManager_ = InputManager::GetInstance();
	player = {500, 500, 30};
	speed_ = 3.0f;
	bullet = {0, 0, 10};
	isAttack = false;
}

void Player::Update()
{
	
}

void Player::Draw() 
{
	Novice::DrawEllipse(
	    static_cast<int>(player.position.x), static_cast<int>(player.position.y),
	    static_cast<int>(player.radius), static_cast<int>(player.radius), 0.0f, WHITE,
	    kFillModeSolid);

	if (isAttack == true) {
		Novice::DrawEllipse(
		    static_cast<int>(bullet.position.x), static_cast<int>(bullet.position.y),
		    static_cast<int>(bullet.radius), static_cast<int>(bullet.radius), 0.0f, WHITE,
		    kFillModeSolid);
	}
}

Object Player::GetBullet() {
	Object result;
	result = bullet;
	return result;
}

void Player::MoveRight() 
{ player.position.x += speed_; }

void Player::MoveLeft() 
{ player.position.x -= speed_; }


