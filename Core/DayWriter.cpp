#include "stdafx.h"
#include "DayWriter.h"

#include "OneDay.h"

namespace DiaryCore
{
	DayWriter::DayWriter(std::ofstream& out) :_out(out)
	{
	}


	DayWriter::~DayWriter()
	{
	}

	void DayWriter::Write(const OneDay& oneDay)
	{
	}

	void DayWriter::Write(const Date& date)
	{
	}

}

