#pragma once
#include "simple_matrix.h"
#include "vector_operations.h"
#include <cmath>
#include <algorithm> 
#include<iostream>
#include<string>

class CSR
{
public:
	CSR(const simple_matrix& M);
	double operator()(std::size_t i, std::size_t j) const;
	std::vector<double> operator*(std::vector<double> vec) const;
	int get_height();


	std::vector<double> MPI(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol);
	std::vector<double> Jacobi(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol);
	std::vector<double> GS(					const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol);
	std::vector<double> Cheb_accel(			const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double lambd_min, const double lambd_max);
	std::vector<double> simmetrical_GS(		const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol);
	std::vector<double> gradient_descent(	const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol);
	double lambda_max();

	std::vector<double> cheb_MPI(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p);
	std::vector<double> cheb_Jacobi(			const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p);
	std::vector<double> cheb_GS(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p);
	std::vector<double> cheb_simmetrical_GS(	const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p);
	std::vector<double> cheb_gradient_descent(	const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p);


	std::vector<double> conjurate_gradient(		const std::vector<double>& b, const std::vector<double>& x0,				const int Nmax,	const double Tol);
	std::vector<double> GMRES(					const std::vector<double>& b, const std::vector<double>& x0, int const& m,	const int Nmax, const double Tol);
private:
	std::vector<double> elements;
	std::vector<int> columns;
	std::vector<int> nonzero;
};


