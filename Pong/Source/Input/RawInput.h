#pragma once

#include "RawInputVisitor.h"

namespace PongGame
{
	class RawInput
	{
	private:
		int id;
	public:
		RawInput(int id);
		virtual ~RawInput();

		virtual void accept(RawInputVisitor& v);

		bool operator==(const RawInput& other);
		bool operator!=(const RawInput& other);
		bool operator< (const RawInput& other);
	};
}