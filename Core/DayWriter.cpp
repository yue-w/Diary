#include "stdafx.h"
#include "DayWriter.h"

#include "OneDay.h"
#include "Byte.h"
#include "FileTags.h"

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
		this->Write(oneDay.GetDate());

		this->WriteContent(oneDay.GetContent());

		_out << endl;
	}

	void DayWriter::Write(const Date& date)
	{
		auto yearBytes = CreateArray(date.Year());
		auto monthBytes = CreateArray(date.Month());
		auto dayBytes = CreateArray(date.Day());

		for (auto b : yearBytes)
		{
			b.Write(_out);
		}
		for (auto b : monthBytes)
		{
			b.Write(_out);
		}
		for (auto b : dayBytes)
		{
			b.Write(_out);
		}
	}

	void DayWriter::WriteContent(const std::string& content)
	{
		auto contentBytes = CreateArray(content);
		for (auto b : contentBytes)
		{
			b.Write(_out);
		}
	}

	std::vector<Byte> DayWriter::CreateArray(const int val) const
	{
		//Split val to digits.
		vector<int> digits;

		int remain;
		int divider = 10;
		do
		{
			int mod = val%divider;
			remain = (int)val / divider;
			digits.push_back(mod);

		} while (remain != 0);

		reverse(digits.begin(), digits.end());

		vector<Byte> res;
		for (auto d : digits)
		{
			res.push_back(Byte(d));
		}

		return res;
	}

	std::vector<Byte> DayWriter::CreateArray(const std::string val) const
	{
		std::vector<Byte> res;
		for (auto ch : val)
		{
			int chInt = (int)ch;
			chInt = -chInt;
			res.push_back(Byte(chInt));
		}

		return res;
	}

}

