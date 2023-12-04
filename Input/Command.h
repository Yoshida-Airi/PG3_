#pragma once
#include<Object/Player.h>

class Command {
public:
	virtual ~Command();
	virtual void Exec(Player& player) = 0;
};

class MoveRightCommand : public Command
{
public:
	void Exec(Player& player) override;
};

class MoveLeftCommand : public Command
{
public:
	void Exec(Player& player) override;
};
