#include "GameManager.h"

GameManager::GameManager() 
{ 
	inputManager = InputManager::GetInstance();

	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
	sceneArr_[TITLE]->Initialize();
}

GameManager::~GameManager() {}

int GameManager::Run()
{
	while (Novice::ProcessMessage() == 0)
	{
		Novice::BeginFrame();

		inputManager->Update();

		//シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_)
		{
			sceneArr_[currentSceneNo_]->Initialize();
		}

		sceneArr_[currentSceneNo_]->Update();

		

		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager->IsKeyTrriger(DIK_ESCAPE))
		{
			break;
		}

	}
	
	Novice::Finalize();
	return 0;
}
