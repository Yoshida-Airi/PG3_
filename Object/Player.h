#pragma once
#include"Manager/InputManager.h"
#include"Novice.h"
#include"Vector2.h"
#include"Object/Object.h"


class Player
{
public:

	void Initialize();
	void Update();
	void Draw();

	Object GetBullet();

	void MoveRight();
	void MoveLeft();

private:
	InputManager* inputManager_;
	Object player;
	Object bullet;

	float speed_;

	bool isAttack;
};
