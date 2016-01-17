#pragma once

#include <memory>
#include "Shape/Circle.h"
#include "Shape/Line.h"
#include "Contact.h"

namespace PongGame
{
namespace Collision
{
std::unique_ptr<Contact> intersect(Circle& r, Line& c);
};
}