#pragma once
#include <vector>
#include <iostream>

class simple_matrix
{
public:
	simple_matrix(std::vector<double> elements, int Width);
	int get_width() const;
	int get_length() const;
	int get_heigth() const;
	double operator()(std::size_t i, std::size_t j) const;
	std::vector<double> operator*(std::vector<double> vec) const;
private:
	std::vector<double> matrixElements;
	int width;
};

std::ostream& operator<<(std::ostream& os, const simple_matrix& M);

