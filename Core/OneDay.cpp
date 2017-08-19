#include "stdafx.h"
#include "OneDay.h"


namespace DiaryCore
{
	OneDay::OneDay(const Date& date) :_date(date)
	{
	}


	OneDay::~OneDay()
	{
	}

	void OneDay::AppendContent(const std::string val)
	{
		_content += val;
	}

}

