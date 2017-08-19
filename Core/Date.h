#pragma once
#include "InOut.h"

namespace DiaryCore
{
	class Date
	{
		int _year;
		int _month;
		int _day;

	public:
		~Date();

		static Date Create(int y, int m, int d);

		int Year() const { return _year; }
		int Month() const { return _month; }
		int Day() const { return _day; }

	private:
		Date(int y, int m, int d);

	};
}


