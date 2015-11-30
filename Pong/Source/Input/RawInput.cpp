#include "RawInput.h"

namespace PongGame
{
	RawInput::RawInput(int id) : id(id) {}

	RawInput::~RawInput() {}

	void RawInput::accept(RawInputVisitor& v)
	{
		v.visit(*this);
	}

	bool RawInput::operator==(const RawInput& other)
	{
		return id == other.id;
	}
	bool RawInput::operator!=(const RawInput& other)
	{
		return !operator==(other);
	}
	bool RawInput::operator< (const RawInput& other)
	{
		return id < other.id;
	}
}