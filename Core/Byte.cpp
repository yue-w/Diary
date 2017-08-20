#include "stdafx.h"
#include "Byte.h"

namespace DiaryCore
{
	Byte::Byte(int val):_byte(val)
	{

	}

	Byte::Byte(char val):_byte(val)
	{

	}

	Byte::~Byte()
	{
	}

	void Byte::Write(std::ofstream& out)
	{
		out << _byte;
	}
}

