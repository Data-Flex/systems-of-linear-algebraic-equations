#include<simple_matrix.h>
#include<gtest/gtest.h>

TEST(transpose, test1)
{
	std::vector<double> elements = { 1, 2, 3, 4, 5, 6, 7, 8 };
	simple_matrix E(elements, 2);
	simple_matrix ET = E.T();
	EXPECT_NEAR(ET.get_width(), E.get_height(), 0.01);
	EXPECT_NEAR(E.get_width(), ET.get_height(), 0.01);
	for (int i = 0; i < E.get_height(); i++) {
		for (int j = 0; j < E.get_width(); j++) {
			EXPECT_NEAR(E(i, j), ET(j, i), 0.01);
		}
	}
}

