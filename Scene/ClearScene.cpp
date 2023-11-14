#include "ClearScene.h"

void ClearScene::Initialize() { inputManager = InputManager::GetInstance(); }

void ClearScene::Update() {
	if (inputManager->IsKeyTrriger(DIK_SPACE)) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "CLEAR");
	Novice::ScreenPrintf(0, 20, "space : nextScene");
}