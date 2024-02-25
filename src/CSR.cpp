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
	std::vector<double> res;
	for (int i = 1; i < nonzero.size(); i++) {
		double value = 0;
		for (int j = nonzero[i-1]; j < nonzero[i]; j++) {
			value += elements[j] * vec[columns[j]];
		}
		res.push_back(value);
	}
	return res;
}