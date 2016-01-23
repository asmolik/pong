#include "LineVisitor.h"

namespace PongGame
{
LineVisitor::LineVisitor(Line& s) : shape(s), value() {}

LineVisitor::~LineVisitor() {}

void LineVisitor::visit(Circle& circle)
{
    value = Collision::intersect(circle, this->shape);
}

void LineVisitor::visit(Line& line)
{

}

void LineVisitor::visit(Rectangle& rect)
{

}

std::unique_ptr<Contact> LineVisitor::get()
{
    return std::move(value);
}
}