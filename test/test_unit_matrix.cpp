#include<simple_matrix.h>
#include<gtest/gtest.h>

TEST(unit, test1)
{
	simple_matrix E = unit_matrix(8, 8);;
	for (int i = 0; i < E.get_height(); i++) {
		for (int j = 0; j < E.get_width(); j++) {
			if (i == j) { EXPECT_NEAR(E(i,j), 1, 0.01); }
			else { EXPECT_NEAR(E(i, j), 0, 0.01); }
		}
	}
}

