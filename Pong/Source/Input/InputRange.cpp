#include "InputRange.h"

namespace PongGame
{
InputRange::InputRange(int id) : Input(id), range(0.0f) {}

InputRange::~InputRange() {}

void InputRange::set(float value)
{
    range = value;
}

float InputRange::get() const
{
    return range;
}

bool InputRange::operator==(const InputRange& other) const
{
    return id == other.id;
}
bool InputRange::operator!=(const InputRange& other) const
{
    return !operator==(other);
}
bool InputRange::operator< (const InputRange& other) const
{
    return id < other.id;
}
}