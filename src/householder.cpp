#include "householder.h"

simple_matrix P(const simple_matrix& M, const std::vector<double>& nu) {
	simple_matrix ret = simple_matrix(M.get_height(), M.get_width());
	for (int j = 0; j < M.get_width(); j++) {
		std::vector<double> x = M.col(j);
		std::vector<double> theta = x - 2 * (x * nu) / (nu * nu) * nu;
		for (int i = 0; i < M.get_height(); i++) {
			ret(i, j) = theta[i];
		}
	}
	return ret;
}

std::pair<simple_matrix, simple_matrix> householder(const simple_matrix& M) {
	simple_matrix Q = unit_matrix(M.get_height(), M.get_width());
	simple_matrix R = M;
	for (int j = 0; j < R.get_width(); j++) {
		std::vector<double> nu = std::vector<double>(R.get_height());
		nu = R.col(j);
		for (int i = 0; i < j; i++) {
			nu[i] = 0;
		}
		nu[j] = nu[j] + sign(nu[j]) * abs(nu);
		R = P(R, nu);
		Q = P(Q.T(), nu).T();
	}
	return std::pair<simple_matrix, simple_matrix>(Q, R);
}

std::vector<double> householder_solve(const simple_matrix& A, const std::vector<double>& f) {
	std::pair<simple_matrix, simple_matrix> QR = householder(A);
	std::vector<double> f1 = QR.first.T() * f;
	std::vector<double> x(f1.size());
	for (int h = f1.size() - 1; h >= 0; h--) {
		for (int w = h+1; w < f1.size(); w++) {
			f1[h] -= x[w] * QR.second(h, w);
		}
		x[h] = f1[h] / QR.second(h, h);
	}
	return x;
}