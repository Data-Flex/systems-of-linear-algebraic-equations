#pragma once
#include "simple_matrix.h"

class CSR
{
public:
	CSR(const simple_matrix& M);
	double operator()(std::size_t i, std::size_t j) const;
	std::vector<double> operator*(std::vector<double> vec) const;
private:
	std::vector<double> elements;
	std::vector<int> columns;
	std::vector<int> nonzero;
};

