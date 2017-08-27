#pragma once
#include "InOut.h"
#include<fstream>
#include<vector>

namespace DiaryCore
{
	//////////////////////////////////////////////////////////////////////////
	//A byte from -128 to 127.
	//////////////////////////////////////////////////////////////////////////
	class Byte
	{
		byte _byte;

	public:
		explicit Byte(int val);
		explicit Byte(byte val);
		~Byte();

		void Write(std::ofstream& out);

		int ToInt() const { return (int)_byte; }
		byte ToChar() const { return _byte; }

		static Byte Read(std::ifstream& in);
	};
}


