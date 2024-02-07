#pragma once
#include <vector>
class three_diag_table
{
public:
	three_diag_table(std::vector<double> A, std::vector<double> B, std::vector<double> C);
	std::vector<double> a, b, c;
};


