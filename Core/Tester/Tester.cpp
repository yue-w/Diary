
#include <gtest\gtest.h>

#include <fstream>
#include <iostream>
#include "../Core/DayWriter.h"
#include "../Core/DayReader.h"
#include "../Core/OneDay.h"

using namespace DiaryCore;
using namespace std;

TEST(Category, TestName)
{
	int i = 10;
	int j = 10;
	int multi = i*j;

	EXPECT_EQ(100, multi);
	EXPECT_TRUE(100 == multi);
}

TEST(Test_DayWriter_DayReader, ReadWriteDayDiary_OneDay)
{
	ofstream out("test");
	DayWriter dw(out);

	OneDay day(Date::Create(2017, 8, 26));
	day.AppendContent("hello world");

	dw.Write(day);

	ifstream in("test");
	DayReader reader(in);
	OneDay diary = reader.Read();

	ASSERT_EQ("hello world", diary.GetContent());
}

TEST(Test_DayWriter_DayReader, ReadWriteDayDiary_TwoDay)
{
	ofstream out("test");
	DayWriter dw(out);

	//First day.
	OneDay day(Date::Create(2017, 8, 26));
	day.AppendContent("hello world");
	dw.Write(day);

	//Second day.
	OneDay day2(Date::Create(2017, 8, 27));
	day2.AppendContent("hello world again!");
	dw.Write(day2);

	ifstream in("test");
	DayReader reader(in);
	OneDay diaryDay1 = reader.Read();
	OneDay diaryDay2 = reader.Read();

	ASSERT_EQ("hello world", diaryDay1.GetContent());
	ASSERT_EQ("hello world again!", diaryDay2.GetContent());
}