#include<simple_matrix.h>
#include<CSR.h>
#include<gtest/gtest.h>

TEST(CSR, test1)
{
	std::vector<double> A = { 1, 2, 0, 3, 0, 0, 4, 0, 0, 1, 0, 11 };
	simple_matrix M(A, 4);
	CSR CS(M);
	for (unsigned int i = 0; i < A.size(); i++) {
		EXPECT_NEAR(A[i], CS(i/4, i%4), 0.01);
	}
}

TEST(CSR, test2)
{
	std::vector<double> A = { 1, 2, 0, 3, 0, 0, 4, 0, 0, 1, 0, 11 };
	simple_matrix M(A, 4);
	CSR CS(M);
	std::vector<double> B = { 3, 4, 5, 6 };
	std::vector<double> C = CS * B;
	std::vector<double> ans = { 29, 20, 70 };
	for (unsigned int i = 0; i < ans.size(); i++) {
		EXPECT_NEAR(ans[i], C[i], 0.01);
	}
}
