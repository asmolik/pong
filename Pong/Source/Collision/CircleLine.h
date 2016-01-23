#pragma once

#include <memory>
#include "Shape/Circle.h"
#include "Shape/Line.h"
#include "Contact.h"
#include "System/Constants.h"

namespace PongGame
{
namespace Collision
{
// Detects collision between a circle and a line.
std::unique_ptr<Contact> intersect(Circle& r, Line& c);
};
}