#include "AddPoint.h"

namespace PongGame
{
AddPoint::AddPoint(GameInfo& i) : info(i) {}

bool AddPoint::collisionResponse(const Contact& contact)
{
    return false;
}

void AddPoint::onCollision(const Contact& contact)
{
    if (contact.object1.name == "left")
    {
        info.player2Score += 1;
    }
    if (contact.object1.name == "right")
    {
        info.player1Score += 1;
    }
}
}