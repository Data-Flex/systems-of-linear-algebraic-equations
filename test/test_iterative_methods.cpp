#include<simple_matrix.h>
#include<CSR.h>
#include<gtest/gtest.h>

TEST(iterative_methods, MPI)
{
	std::vector<double> A = { 2, 1, 0, 0, 5, 0, 4, 0, 3 };
	simple_matrix S(A, 3);
	CSR M(S);
	std::vector<double> ans = { 1, 1, 1 };
	std::vector<double> x_0 = { 2, 2, 2 };
	std::vector<double> b = M * ans;
	std::vector<double> x = M.MPI(b, x_0, 10000, 1e-20);
	for (unsigned int i = 0; i < ans.size(); i++) {
		EXPECT_NEAR(ans[i], x[i], 0.01);
	}
}


TEST(iterative_methods, Jacobi)
{
	std::vector<double> A = { 2, 1, 0, 0, 5, 0, 4, 0, 3 };
	simple_matrix S(A, 3);
	CSR M(S);
	std::vector<double> ans = { 1, 1, 1 };
	std::vector<double> x_0 = { 2, 2, 2 };
	std::vector<double> b = M * ans;
	std::vector<double> x = M.Jacobi(b, x_0, 10000, 1e-20);
	for (unsigned int i = 0; i < ans.size(); i++) {
		EXPECT_NEAR(ans[i], x[i], 0.01);
	}
}


TEST(iterative_methods, GS)
{
	std::vector<double> A = { 2, 1, 0, 0, 5, 0, 4, 0, 3 };
	simple_matrix S(A, 3);
	CSR M(S);
	std::vector<double> ans = { 1, 1, 1 };
	std::vector<double> x_0 = { 2, 2, 2 };
	std::vector<double> b = M * ans;
	std::vector<double> x = M.GS(b, x_0, 10000, 1e-20);
	for (unsigned int i = 0; i < ans.size(); i++) {
		EXPECT_NEAR(ans[i], x[i], 0.01);
	}
}
