#include "StageScene.h"


void StageScene::Initialize()
{ 
	inputHandler_ = new InputHandler();
	inputManager = new InputManager();

	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	player = new Player;
	player->Initialize();

}

void StageScene::Update() {

	commad_ = inputHandler_->HandleInput();

	if (this->commad_)
	{
		commad_->Exec(*player);
	}

	player->Update();

}

void StageScene::Draw() {

	player->Draw();
	
	Novice::ScreenPrintf(0, 0, "STAGE");
	Novice::ScreenPrintf(0, 20, "A or D : move");
}
