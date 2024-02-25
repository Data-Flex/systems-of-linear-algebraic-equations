#include<simple_matrix.h>
#include<gtest/gtest.h>

TEST(simple, test1)
{
	std::vector<double> A = { 5, 6 };
	std::vector<double> B = { 1, 2, 3, 4, 5, 6 };
	simple_matrix M(B, 2);
	std::vector<double> C = M * A;
	std::vector<double> ans = { 17, 39, 61 };
	for (unsigned int i = 0; i < ans.size(); i++) {
		EXPECT_NEAR(C[i], ans[i], 0.01);
	}
}