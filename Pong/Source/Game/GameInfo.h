#pragma once

#include "Physics/Vec2.h"

namespace PongGame
{
//
// Information about a pong game.
//
struct GameInfo
{
    int player1Score;
    int player2Score;
    int maxScore;

    Vec2 ballPos;
    Vec2 p1Pos;
    Vec2 p2Pos;

    float fieldWidth, fieldHeight;
    float ballSize;
    float paddle1Length;
    float paddle2Length;
    Vec2 initialSpeed;

    GameInfo();
};
}