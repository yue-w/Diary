#include "stdafx.h"
#include "Byte.h"

namespace DiaryCore
{
	Byte::Byte(int val):_byte(val)
	{

	}

	Byte::Byte(byte val):_byte(val)
	{

	}

	Byte::~Byte()
	{
	}

	void Byte::Write(std::ofstream& out)
	{
		out << _byte;
	}

	Byte Byte::Read(std::ifstream& in)
	{
		byte ch;
		in >> ch;

		return Byte(ch);
	}

}

