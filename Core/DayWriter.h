#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace DiaryCore
{
	class Date;
	class OneDay;
	class Byte;

	class DayWriter
	{
		std::ofstream& _out;
	public:
		DayWriter(std::ofstream& out);
		~DayWriter();

		void Write(const OneDay& oneDay);

	private:
		void Write(const Date& date);
		void WriteContent(const std::string& content);

	private:

		//Create byte array from an integer.
		std::vector<Byte> CreateArray(const int val) const;
		//Create byte array from string.
		std::vector<Byte> CreateArray(const std::string val) const;
	};
}


