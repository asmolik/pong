#pragma once

namespace PongGame
{
namespace Constants
{
// constant used in physics simulation. It is used when comparing two numbers,
// as exact comparison (==) is not reliable with floating point numbers.
static const float epsilon = 0.01f;
};
}