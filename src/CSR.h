#pragma once
#include "simple_matrix.h"
#include "vector_operations.h"

class CSR
{
public:
	CSR(const simple_matrix& M);
	double operator()(std::size_t i, std::size_t j) const;
	std::vector<double> operator*(std::vector<double> vec) const;
	int get_height();


	std::vector<double> MPI(const std::vector <double>& b, std::vector <double> x, const int Nmax, const double Tol);
	std::vector<double> Jacobi(const std::vector <double>& b, const std::vector <double>& x, int Nmax, double Tol);
	std::vector<double> GS(const std::vector <double>& b, const std::vector <double>& x, int Nmax, double Tol);
private:
	std::vector<double> elements;
	std::vector<int> columns;
	std::vector<int> nonzero;
};

