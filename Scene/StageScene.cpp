#include "StageScene.h"


void StageScene::Initialize()
{ 
	inputManager = InputManager::GetInstance();
	player = new Player;
	enemy = new Enemy;
	player->Initialize();
	enemy->Initialize();
}

void StageScene::Update() {


	player->Update();
	enemy->Update();

	//敵と弾の当たり判定
	Vector2 distance;
	distance.x = player->GetBullet().position.x - enemy->GetEnemy().position.x;
	distance.y = player->GetBullet().position.y - enemy->GetEnemy().position.y;
	// 円の中心の距離を計算（右辺）
	float d = distance.x * distance.x + distance.y * distance.y;
	// 敵の半径と弾の半径を足して二乗（左辺）
	float r = (enemy->GetEnemy().radius + player->GetBullet().radius) *
	        (enemy->GetEnemy().radius + player->GetBullet().radius);
	

	if (r == d || r > d) {
		enemy->SetAlive(false);
	}

	if (inputManager->IsKeyTrriger(DIK_SPACE)) {
		sceneNo = CLEAR;
	}


}

void StageScene::Draw() {

	player->Draw();
	enemy->Draw();
	
	Novice::ScreenPrintf(0, 0, "STAGE");
	Novice::ScreenPrintf(0, 20, "space : nextScene");
	Novice::ScreenPrintf(0, 40, "enter : Attack");
}
