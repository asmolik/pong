#pragma once

#include <memory>
#include "Physics/Vec2.h"
#include "Shape/Circle.h"
#include "Shape/Rectangle.h"
#include "Contact.h"
#include "System/Constants.h"

namespace PongGame
{
namespace Collision
{
// Detects collision between a circle and a line segment.
std::unique_ptr<Contact> intersect(Rectangle& r, Circle& c);
};
}