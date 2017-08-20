#include "stdafx.h"
#include "DayReader.h"

#include "OneDay.h"

namespace DiaryCore
{
	DayReader::DayReader(std::ifstream &in) :_in(in)
	{

	}

	DayReader::~DayReader()
	{
	}

	DiaryCore::OneDay DayReader::Read() const
	{
		throw std::runtime_error("");
	}

}

