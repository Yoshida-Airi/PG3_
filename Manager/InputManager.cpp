#include "InputManager.h"

InputManager* InputManager::GetInstance(){
	if (instance == NULL)
	{
		instance = new InputManager;
	}
	return instance;
}

InputManager::~InputManager() {}

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

bool InputManager::IsKeyPressed(int keyCode) { // ESCキーが押されたらループを抜ける
	if (keys[keyCode]) 
	{
		return true;
	}

	return false;
}

bool InputManager::IsKeyTrriger(int keyCode) 
{
	if (preKeys[keyCode] != 0 && keys[keyCode] == 0) {
		return true;
	}

	return false;
}


InputManager* InputManager::instance = NULL;