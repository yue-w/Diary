
#include <gtest\gtest.h>

TEST(Category, TestName)
{
	int i = 10;
	int j = 10;
	int multi = i*j;

	EXPECT_EQ(100, multi);
	EXPECT_TRUE(100 == multi);
}