#pragma once
#include "InOut.h"
#include <fstream>
#include <string>
#include <vector>

namespace DiaryCore
{
	class OneDay;
	class Date;
	class Byte;

	//////////////////////////////////////////////////////////////////////////
	//Reader from a file stream to Diary.
	//////////////////////////////////////////////////////////////////////////
	class _DIARY_CORE_API DayReader
	{
		std::ifstream &_in;
	public:
		DayReader(std::ifstream &in);
		~DayReader();

		OneDay Read() const;

	private: 

		void ReadStartTag() const;
		Date ReadDate() const;
		std::string ReadContent() const;

		std::vector<Byte> ReadToEnd() const;

		std::vector<Byte> ReadBytes(const int count) const;
	};
}


