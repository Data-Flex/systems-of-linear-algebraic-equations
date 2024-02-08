#pragma once
#include <vector>
class three_diag_table
{
public:
	three_diag_table(const std::vector<double>& A, const std::vector<double>& B, const std::vector<double>& C);
	std::vector<double> a, b, c;
};


