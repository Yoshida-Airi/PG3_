#pragma once
#include "IScene.h"
#include"Manager/InputManager.h"
#include"Vector2.h"
#include"Object/Player.h"
#include"Object/Enemy.h"

class StageScene : public IScene
{
public:

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	InputManager* inputManager;
	Player* player;
	Enemy* enemy;

};
