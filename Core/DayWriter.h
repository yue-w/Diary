#pragma once
#include "InOut.h"
#include <fstream>
#include <string>
#include <vector>

namespace DiaryCore
{
	class Date;
	class OneDay;
	class Byte;

	//////////////////////////////////////////////////////////////////////////
	//Reader from Diary to a file stream.
	//////////////////////////////////////////////////////////////////////////
	class _DIARY_CORE_API DayWriter
	{
		std::ofstream& _out;
	public:
		DayWriter(std::ofstream& out);
		~DayWriter();

		void Write(const OneDay& oneDay);

	private:
		void Write(const Date& date);
		void WriteContent(const std::string& content);
		void WriteDayStartTag();
		void WriteDayEndTag();

	private:

		//Create byte array from an integer.
		std::vector<Byte> CreateArray(const int val) const;
		//Create byte array from string.
		std::vector<Byte> CreateArray(const std::string val) const;
	};
}


