#include<progonka.h>
#include<three_diag_table.h>
#include<gtest/gtest.h>

TEST(matrix, solve)
{
    std::vector<double> a = { 0, 2, 5, 8, 2 };
    std::vector<double> b = { 11, 14, 17, 11, 14 };
    std::vector<double> c = { 3, 6, 9, 3, 0 };
    three_diag_table x(a, b, c);
    std::vector<double> d = { 1, 2, 3, 4, 5 };
    std::vector<double> s = progonka(x, d);

    EXPECT_EQ(s.size(), 5);
};

TEST(matrix, solve1)
{
    std::vector<double> a = { 0, 0.0475, 0.0523, 0.057 };
    std::vector<double> b = { 10.8, 9.9, 9, 8.1 };
    std::vector<double> c = { 0.0321, 0.0369, 0.0416, 0 };
    three_diag_table x(a, b, c);
    std::vector<double> d = { 12.143, 13.0897, 13.6744, 13.8792 };
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[0], 1.12, 0.01);
}

TEST(matrix, solve2)
{
    std::vector a = { 0., 0.0475, 0.0523, 0.057 };
    std::vector b = { 10.8, 9.9, 9., 8.1 };
    std::vector c = { 0.0321, 0.0369, 0.0416, 0. };
    three_diag_table x(c, b, a);
    std::vector d = { 12.143, 13.0897, 13.6744, 13.8792 };
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[1], 1.31, 0.01);
}

TEST(matrix, solve3)
{
    std::vector a = { 0., 0.0475, 0.0523, 0.057 };
    std::vector b = { 10.8, 9.9, 9., 8.1 };
    std::vector c = { 0.0321, 0.0369, 0.0416, 0. };
    three_diag_table x(c, b, a);
    std::vector d = { 12.143, 13.0897, 13.6744, 13.8792 };
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[2], 1.5, 0.01);
}

TEST(matrix, solve4)
{
    std::vector a = { 0., 0.0475, 0.0523, 0.057 };
    std::vector b = { 10.8, 9.9, 9., 8.1 };
    std::vector c = { 0.0321, 0.0369, 0.0416, 0. };
    three_diag_table x(c, b, a);
    std::vector d = { 12.143, 13.0897, 13.6744, 13.8792 };
    std::vector<double> s = progonka(x, d);

    EXPECT_NEAR(s[3], 1.7, 0.01);
}



// 1.12, 1.31, 1.5, 1.7}