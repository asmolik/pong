#pragma once

#include "Game/Game.h"

class Pong
{
private:
	int x;
    PongGame::Game pong;

public:
    Pong(int x);

	int get();

	void run();
};

