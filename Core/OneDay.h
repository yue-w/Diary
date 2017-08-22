#pragma once
#include "InOut.h"
#include "Date.h"
#include <string>

namespace DiaryCore
{
	class OneDay
	{
		Date _date;

		std::string _content;

		friend class DayWriter;

	public:
		OneDay(const Date& date);
		~OneDay();

		void AppendContent(const std::string val);
		Date GetDate() const { return _date; }
		std::string GetContent() const { return _content; }
	};
}


