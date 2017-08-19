#pragma once
#include <fstream>

namespace DiaryCore
{
	class Date;
	class OneDay;

	class DayWriter
	{
		std::ofstream& _out;
	public:
		DayWriter(std::ofstream& out);
		~DayWriter();

		void Write(const OneDay& oneDay);

	private:
		void Write(const Date& date);


	private:
	};
}


