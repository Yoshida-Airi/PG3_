#include "Player.h"

void Player::Initialize() 
{
	inputManager_ = InputManager::GetInstance();
	player = {500, 500, 30};
	bullet = {0, 0, 10};
	isAttack = false;
}

void Player::Update()
{
	// プレイヤーの移動
	if (inputManager_->IsKeyPressed(DIK_W)) {
		player.position.y -= 3.0f;
	}
	if (inputManager_->IsKeyPressed(DIK_S)) {
		player.position.y += 3.0f;
	}
	if (inputManager_->IsKeyPressed(DIK_A)) {
		player.position.x -= 3.0f;
	}
	if (inputManager_->IsKeyPressed(DIK_D)) {
		player.position.x += 3.0f;
	}

	if (isAttack == false) {
		if (inputManager_->IsKeyTrriger(DIK_RETURN)) {
			bullet.position = player.position;
			isAttack = true;
		}
	}

	if (isAttack == true)
	{
		bullet.position.y -= 6.0f;
	}

	if (bullet.position.y <= -30) {
		isAttack = false;
	}

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


