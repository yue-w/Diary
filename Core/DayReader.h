#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace DiaryCore
{
	class OneDay;

	class DayReader
	{
		std::ifstream &_in;
	public:
		DayReader(std::ifstream &in);
		~DayReader();

		OneDay Read() const;
	};
}


