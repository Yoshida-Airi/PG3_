#pragma once
#include"Novice.h"

class InputManager 
{
public:
	static InputManager* GetInstance();

	 ~InputManager();

	void Update();

	bool IsKeyPressed(int keyCode);

	bool IsKeyTrriger(int keyCode);

private:

	static InputManager* instance;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

};
