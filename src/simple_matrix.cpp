#include "simple_matrix.h"

simple_matrix::simple_matrix(std::vector<double> elements, int Width) : matrixElements(elements), width(Width) {}

int simple_matrix::get_width() const{
	return width;
}

int simple_matrix::get_length() const {
	return matrixElements.size();
}

int simple_matrix::get_heigth() const {
	return matrixElements.size() / width;
}


double simple_matrix::operator()(std::size_t i, std::size_t j) const {
	return matrixElements[i * width + j];
}

std::vector<double> simple_matrix::operator*(std::vector<double> vec) const {
	std::vector<double> new_vec;
	for (int i = 0; i < this->get_heigth(); i++) {
		double value = 0;
		for (int j = 0; j < width; j++) {
			value += matrixElements[i * width + j]*vec[j];
		}
		new_vec.push_back(value);
	}
	return new_vec;
}

std::ostream& operator<<(std::ostream& os, const simple_matrix& M) {
	for (int i = 0; i < M.get_heigth(); i++) {
		for (int j = 0; j < M.get_width(); j++) {
			os << M(i, j) << " ";
		}
		std::cout << std::endl;
	}
	return os;
}