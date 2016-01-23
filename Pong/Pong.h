#pragma once

#include "Game/Game.h"
#include "Game/GameInfo.h"
#include "Input/InputRange.h"

class Pong
{
private:
    PongGame::Game pong;

public:
    Pong();

    void setWidth(float width);
    void setHeight(float height);
    void setBallVelocity(float x, float y);
    void setBallPosition(float x, float y);

    // Steps the game by specified time step.
    void run(float time);

    // Input for player 1. Range [-1.0; 1.0].
    void p1input(float range);
    // Input for player 2. Range [-1.0; 1.0].
    void p2input(float range);
	
    // Returns the game's state.
    PongGame::GameInfo get();
    int p1score();
    int p2score();
};

