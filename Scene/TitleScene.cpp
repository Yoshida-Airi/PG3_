#include "TitleScene.h"

void TitleScene::Initialize() { inputManager = InputManager::GetInstance(); }

void TitleScene::Update() {

	
	if (inputManager->IsKeyTrriger(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() 
{ 
	Novice::ScreenPrintf(0, 0, "TITLE");
	Novice::ScreenPrintf(0, 20, "space : nextScene");
}
