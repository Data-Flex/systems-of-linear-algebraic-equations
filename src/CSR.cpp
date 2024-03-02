#include "CSR.h"

CSR::CSR(const simple_matrix& M) {
	int count_nonzero = 0;
	nonzero.push_back(0);
	for (int i = 0; i < M.get_height(); i++) {
		for (int j = 0; j < M.get_width(); j++) {
			if (M(i, j) != 0) {
				elements.push_back(M(i, j));
				columns.push_back(j);
				count_nonzero++;
			}
		}
		nonzero.push_back(count_nonzero);
	}
}

double CSR::operator()(std::size_t i, std::size_t j) const {
	double value = 0;
	for (int k = nonzero[i]; k < nonzero[i + 1]; k++) {
		if (columns[k] == j) {
			value = elements[k];
			break;
		}
	}
	return value;
}

std::vector<double> CSR::operator*(std::vector<double> vec) const {
	std::vector<double> res(nonzero.size()-1);
	for (int i = 1; i < nonzero.size(); i++) {
		double value = 0;
		for (int j = nonzero[i-1]; j < nonzero[i]; j++) {
			value += elements[j] * vec[columns[j]];
		}
		res[i-1] = value;
	}
	return res;
}


int CSR::get_height() {
	return nonzero.size();
}




std::vector<double> CSR::MPI(const std::vector <double>& b, std::vector <double> x, const int Nmax, const double Tol) {
	double tay = 0.2;
	std::vector <double> res = x;
	for (int i = 0; i < Nmax; i++) {
		res = res - tay * ((*this) * res - b);
		if (abs((*this) * res - b) < Tol) { break; }
	}
	return res;
}

std::vector<double> CSR::Jacobi(const std::vector <double>& b, const std::vector <double>& x, int Nmax, double Tol) {
	std::vector<double> res = x;
	for (int N = 0; N < Nmax; N++) {
		for (int i = 0; i < nonzero.size()-1; i++) {
			double d = 0;
			double sum = 0;
			for (int k = nonzero[i]; k < nonzero[i + 1]; k++) {
				if (i != columns[k]) {
					sum += elements[k] * res[columns[k]];
				}
				else {
					d = elements[k];
				}
			}
			res[i] = (b[i] - sum) / d;
		}
		if (abs((*this) * res - b) < Tol) { break; }
	}
	return res;
}

std::vector<double> CSR::GS(const std::vector <double>& b, const std::vector <double>& x_0, int Nmax, double Tol) {
	std::vector<double> x = x_0;
	double d = 0;
	for (int N = 0; N < Nmax; N++) {
		for (int i = 0; i < nonzero.size()-1; i++) {
			double d = 0;
			double sum = 0;
			for (int k = nonzero[i]; k < nonzero[i+1]; k++) {
				if (i != columns[k]) {
					sum += elements[k] * x[columns[k]];
				}
				else {
					d = elements[k];
				}
			}
			x[i] = (b[i] - sum) / d;
		}
		if (abs((*this) * x - b) < Tol) { break; }
	}
	return x;
}