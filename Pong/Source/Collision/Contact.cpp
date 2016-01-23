#include "RectangleCircle.h"

namespace PongGame
{
Contact::Contact(GameObject& object1, GameObject& object2, Vec2 normal,
    float toi) 
    : object1(object1), object2(object2), normal(normal), point1(point1), 
    point2(point2), timeOfImpact(toi) {}
}