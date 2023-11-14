#pragma once
#include"manager/InputManager.h"
#include"Novice.h"
#include"Vector2.h"
#include"Object/Object.h"

class Enemy 
{
public:
	void Initialize();
	void Update();
	void Draw();

	Object GetEnemy();
	void SetAlive(bool Alive);

private:
	InputManager* inputManager_;
	Object enemy;

	bool isAlive;
};
