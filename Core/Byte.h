#pragma once
#include<fstream>
#include<vector>

namespace DiaryCore
{
	class Byte
	{
		char _byte;

	public:
		Byte(int val);
		Byte(char val);
		~Byte();

		void Write(std::ofstream& out);
	};
}


