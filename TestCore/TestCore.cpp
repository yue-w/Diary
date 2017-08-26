// TestCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <fstream>
#include <iostream>
#include "../Core/DayWriter.h"
#include "../Core/DayReader.h"
#include "../Core/OneDay.h"

using namespace DiaryCore;
using namespace std;

int main()
{
	ofstream out("test");
	DayWriter dw(out);
	
	OneDay day(Date::Create(2017, 8, 26));
	day.AppendContent("hello world");

	dw.Write(day);

	ifstream in("test");
	DayReader reader(in);
	OneDay diary = reader.Read();

	//Output hello world.
	cout << diary.GetContent() << endl;

    return 0;
}

