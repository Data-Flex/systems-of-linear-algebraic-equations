#include"vector_operations.h"
#include<gtest/gtest.h>

TEST(vector_operation, test1)
{
	std::vector<double> A = { 1, 2, 3, 4 };
	std::vector<double> B = { 3, 4, 5, 6 };
	std::vector<double> C = { 9, 8, 7, 6 };
	double D = (4 * B) * (A + C);
	double ans = 120 + 160 + 200 + 240;
	EXPECT_NEAR(ans, D, 0.01);
}

TEST(vector_operation, test_abs)
{
	std::vector<double> r(9, 1);
	EXPECT_NEAR(abs(r), 3, 0.01);
}