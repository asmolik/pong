#pragma once

#include <memory>
#include "Shape/Circle.h"
#include "Shape/Rectangle.h"
#include "Contact.h"

namespace PongGame
{
namespace Collision
{
std::unique_ptr<Contact> intersect(Rectangle& r, Circle& c);
};
}