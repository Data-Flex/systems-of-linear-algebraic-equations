#include<householder.h>
#include<gtest/gtest.h>

TEST(housholder, decomp)
{
	std::vector<double> vec = { 3, 1, 1,
								4, 5, 8,
								5, 12, 15 };
	simple_matrix A(vec, 3);
	std::pair<simple_matrix, simple_matrix> QR = householder(A);
	simple_matrix A_new = QR.first * QR.second;
	for (int i = 0; i < A.get_height(); i++) {
		for (int j = 0; j < A.get_width(); j++) {
			EXPECT_NEAR(A(i, j), A_new(i, j), 0.01);
		}
	}
}


TEST(housholder, solve)
{
	std::vector<double> vec = { 2, 3, 4,
								3, 2, 1,
								2, 2, 4 };
	simple_matrix A(vec, 3);
	std::vector<double> f = { 33, 17, 30 };
	std::vector<double> x = householder_solve(A, f);
	std::vector<double> res = { 2, 3, 5 };
	for (unsigned int i = 0; i < x.size(); i++) {
		EXPECT_NEAR(x[i], res[i], 0.01);
	}
}