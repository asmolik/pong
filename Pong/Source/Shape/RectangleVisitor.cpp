#include "RectangleVisitor.h"

namespace PongGame
{
RectangleVisitor::RectangleVisitor(Rectangle& s) : shape(s) {}

RectangleVisitor::~RectangleVisitor() {}

void RectangleVisitor::visit(Circle& circle)
{
    value = Collision::intersect(this->shape, circle);
}

void RectangleVisitor::visit(Line& shape)
{

}

void RectangleVisitor::visit(Rectangle& shape)
{

}

std::unique_ptr<Contact> RectangleVisitor::get()
{
    return std::move(value);
}
}