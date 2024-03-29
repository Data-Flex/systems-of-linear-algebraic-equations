#include"CSR.h"

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


double CSR::lambda_max()
{
	double tol = 1e-20;
	std::vector<double> r(max(columns)+1);
	for (int i = 0; i < r.size(); i++)
		r[i] = 1;
	double mu = 0, prev;
	
	for (int i = 0; i < 10000; i++)
	{	
		prev = mu;
		r = (*(this) * r) / abs(*(this) * r);
		mu = r * (*(this) * r) / (r*r);
		if (mu - prev < tol) break;
	}
	return mu;

}


std::vector<double> CSR::MPI(const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	double tay = 0.01;
	std::vector <double> res = x0;
	for (int i = 0; i < Nmax; i++) {
		res = res - tay * ((*this) * res - b);
		if (abs((*this) * res - b) < Tol) { break; }
	}
	return res;
}

std::vector<double> CSR::gradient_descent(const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	double tay = 0;
	std::vector <double> res = x0;
	for (int i = 0; i < Nmax; i++) {
		std::vector<double> r = (*this) * res - b;
		tay = (r * r) / (r*((*this)*r));
		res = res - tay * ((*this) * res - b);
		if (abs((*this) * res - b) < Tol) { break; }
	}
	return res;
}

std::vector<double> CSR::Jacobi(const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	std::vector<double> res = x0;
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

std::vector<double> CSR::GS(const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	std::vector<double> x = x0;
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


std::vector<double> CSR::Cheb_accel(const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double lambd_min, const double lambd_max) {
	std::vector<int> order = { 0, 7, 3, 4, 1, 6, 2, 5 };
	double pi = 3.14159265358979323846;
	int n = 8;
	std::vector<double> res = x0;
	for (int i = 0; i < Nmax; i++) {
		double tay = 1 / ((lambd_max + lambd_min) / 2 + (lambd_max - lambd_min) / 2 * cos(pi * (2 * order[i%8] + 1) / (2 * n)));
		//std::cout << tay << std::endl;
		res = res - tay * ((*this)*res - b);
		if (abs((*this) * res - b) < Tol) { break; }
	}
	return res;
}


std::vector<double> CSR::simmetrical_GS(const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	std::vector<double> x = x0;
	double d = 0;
	for (int N = 0; N < Nmax; N++) {
		for (int i = 0; i < nonzero.size() - 1; i++) {
			double d = 0;
			double sum = 0;
			for (int k = nonzero[i]; k < nonzero[i + 1]; k++) {
				if (i != columns[k]) {
					sum += elements[k] * x[columns[k]];
				}
				else {
					d = elements[k];
				}
			}
			x[i] = (b[i] - sum) / d;
		}
		for (int i = nonzero.size() - 1; i >= 0; i--) {
			double d = 0;
			double sum = 0;
			for (int k = nonzero[i]; k < nonzero[i + 1]; k++) {
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