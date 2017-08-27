#include "stdafx.h"
#include "Date.h"

namespace DiaryCore
{
	Date::Date(int y, int m, int d):_year(y),_month(m),_day(d)
	{
	}


	Date::~Date()
	{
	}

	DiaryCore::Date Date::Create(int y, int m, int d)
	{
		return Date(y, m, d);
	}

}

