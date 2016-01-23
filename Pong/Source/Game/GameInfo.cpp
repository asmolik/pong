#include "GameInfo.h"

namespace PongGame
{
GameInfo::GameInfo() : player1Score(0), player2Score(0), maxScore(10),
fieldWidth(160.0f), fieldHeight(90.0f), ballSize(20.0f), paddle1Length(80.0f),
paddle2Length(80.0f), initialSpeed(Vec2(10.0f))
{ }
}