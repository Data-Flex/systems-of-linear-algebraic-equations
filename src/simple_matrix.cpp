#include "simple_matrix.h"
#include"vector_operations.h"
#include<cmath>

simple_matrix::simple_matrix(std::vector<double> elements, int Width) : matrixElements(elements), width(Width), height(elements.size() / width) {}

simple_matrix::simple_matrix(int Height, int Width) : matrixElements(std::vector<double>(Height * Width, 0)), width(Width), height(Height) {}


int simple_matrix::get_width() const{
	return width;
}

int simple_matrix::get_length() const {
	return height*width;
}

int simple_matrix::get_height() const {
	return height;
}


std::vector<double> simple_matrix::col(int j) const {
	std::vector<double> ret(height);
	for (int i = 0; i < width; i++) { ret[i] = matrixElements[i * width + j]; }
	return ret;
}


double simple_matrix::operator()(int i, int j) const {
	return matrixElements[i * width + j];
}

double &simple_matrix::operator()(int i, int j) {
	return this->matrixElements[i * this->width + j];
}


std::vector<double> simple_matrix::operator*(std::vector<double> vec) const {
	std::vector<double> new_vec;
	for (int i = 0; i < this->get_height(); i++) {
		double value = 0;
		for (int j = 0; j < width; j++) {
			value += matrixElements[i * width + j]*vec[j];
		}
		new_vec.push_back(value);
	}
	return new_vec;
}


simple_matrix simple_matrix::T() {
	simple_matrix ret(width, height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ret(j, i) = matrixElements[i * width + j];
		}
	}
	return ret;
}


//-----------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const simple_matrix& M) {
	for (int i = 0; i < M.get_height(); i++) {
		for (int j = 0; j < M.get_width(); j++) {
			os << M(i, j) << " ";
		}
		std::cout << std::endl;
	}
	return os;
}

//-----------------------------------------------------------------

simple_matrix unit_matrix(int Height, int Width) {
	simple_matrix ret(Height, Width);
	for (int i = 0; i < fmin(Height, Width); i++) {
		ret(i, i) = 1;
	}
	return ret;
}


simple_matrix operator*(const simple_matrix& A, const simple_matrix& B) {
	simple_matrix ret(A.get_height(), B.get_width());
	if (B.get_height() != A.get_width()) {
		std::cout << "operator* error" << std::endl;
		return ret;
	}
	for (int i = 0; i < A.get_height(); i++) {
		for (int j = 0; j < B.get_width(); j++) {
			double value = 0;
			for (int k = 0; k < A.get_width(); k++) {
				value += A(i, k) * B(k, j);
			}
			ret(i, j) = value;
		}
	}
	return ret;
}





