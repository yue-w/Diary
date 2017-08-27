#include "stdafx.h"
#include "DayReader.h"

#include "OneDay.h"
#include "Byte.h"
#include "FileTags.h"

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
		ReadStartTag();

		Date date = ReadDate();

		string content = ReadContent();

		OneDay res(date);
		res.AppendContent(content);

		return res;
	}

	void DayReader::ReadStartTag() const
	{
		auto startBytes = ReadBytes(5);
		for (size_t i = 0; i < startBytes.size(); ++i)
		{
			if (startBytes[i].ToChar() != DAY_START[i])
			{
				throw invalid_argument("The start tag of diary is incorrect!");
			}
		}
	}

	DiaryCore::Date DayReader::ReadDate() const
	{
		//Parse year.
		vector<Byte> yearBytes = ReadBytes(4);
		int year = 0;
		int multiple = 1;
		for (int i = (int)yearBytes.size() - 1; i >= 0; --i)
		{
			int digit = yearBytes[i].ToInt();
			year += multiple*digit;
			multiple *= 10;
		}

		//Parse month.
		vector<Byte> monthBytes = ReadBytes(2);
		int month = monthBytes[0].ToInt() * 10 + monthBytes[1].ToInt();

		//Parse day.
		vector<Byte> dayBytes = ReadBytes(2);
		int day = dayBytes[0].ToInt() * 10 + dayBytes[1].ToInt() ;

		return Date::Create(year, month, day);
	}

	std::string DayReader::ReadContent() const
	{
		vector<Byte> contentBytes = ReadToEnd();

		//Parse.
		string content = "";
		for (auto byte : contentBytes)
		{
			int intByte = byte.ToInt();
			intByte = -intByte;
			content += (char)intByte;
		}

		return content;
	}

	std::vector<Byte> DayReader::ReadToEnd() const
	{
		vector<Byte> bytes;
		//Read until end tag.
		byte ch;
		int matchEndCount = 0;
		int matchEndIndex = 0;
		do
		{
			_in >> ch;

			if (ch == DAY_END[matchEndIndex])
			{
				//One of bytes matches with end tag.
				matchEndCount++;
				matchEndIndex++;
			}
			else
			{
				//Not match with end tag.
				//Then push back the byte and reset <matchEndCount> and <matchEndIndex>.
				bytes.push_back(Byte(ch));
				matchEndCount = 0;
				matchEndIndex = 0;
			}

			if(matchEndCount==5)
			{
				break;
			}

		} while (true);

		return bytes;
	}

	vector<Byte> DayReader::ReadBytes(const int count) const
	{
		vector<Byte> res;
		for (int i = 0; i < count; ++i)
		{
			res.push_back(Byte::Read(_in));
		}

		return res;
	}

}

