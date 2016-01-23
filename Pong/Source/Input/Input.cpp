#include "Input.h"

namespace PongGame
{
Input::Input(int id) : id(id) {}

Input::~Input() {}

bool Input::operator==(const Input& other) const
{
    return id == other.id;
}
bool Input::operator!=(const Input& other) const
{
    return !operator==(other);
}
bool Input::operator< (const Input& other) const
{
    return id < other.id;
}
}