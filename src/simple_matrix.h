#pragma once
#include <vector>
#include <iostream>

class simple_matrix
{
public:
	simple_matrix(std::vector<double> elements, int Width);
	simple_matrix(int Height, int Width);
	int get_width() const;
	int get_length() const;
	int get_height() const;
	std::vector<double> col(int j) const;
	std::vector<double> row(int i) const;
	double operator()(int i, int j) const;
	double& operator()(int i, int j);
	std::vector<double> operator*(std::vector<double> vec) const;
	simple_matrix T();
	std::vector<double> vals() const;
private:
	std::vector<double> matrixElements;
	int width, height;
};

std::ostream& operator<<(std::ostream& os, const simple_matrix& M);
simple_matrix operator*(const simple_matrix& A, const simple_matrix& B);

simple_matrix unit_matrix(int Height, int Width);

simple_matrix add_col(	simple_matrix& M, std::vector<double> const& v);
simple_matrix add_col_H(simple_matrix& M, std::vector<double> const& v);
std::vector<double> Inverse_Gauss_Method(simple_matrix const& A, std::vector<double> const& f);
