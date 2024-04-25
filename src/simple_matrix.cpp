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

std::vector<double> simple_matrix::row(int i) const {
	std::vector<double> ret(width);
	for (int j = 0; j < width; j++) { ret[j] = matrixElements[i * width + j]; }
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

//-----------------------------------------------------------------

simple_matrix add_col_H(simple_matrix& M, std::vector<double> const& v)
{
	std::vector<double> res_vals;
	for (std::size_t i = 0; i < M.get_height(); ++i)
	{
		for (std::size_t j = 0; j < M.get_width(); ++j)
			res_vals.push_back(M.vals()[i * M.get_width() + j]);
		res_vals.push_back(v[i]);
	}

	for (std::size_t j = 0; j <= M.get_width(); ++j)
		if (j == M.get_height()) res_vals.push_back(v[j]);
		else res_vals.push_back(0);

	return simple_matrix(res_vals, M.get_width() + 1);
}


simple_matrix add_col(simple_matrix& M, std::vector<double> const& v)
{
	std::vector<double> res_vals;
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		for (std::size_t j = 0; j < M.get_width(); ++j)
			res_vals.push_back(M.vals()[i * M.get_width() + j]);
		res_vals.push_back(v[i]);
	}

	return simple_matrix(res_vals, M.get_width() + 1);
}



std::vector<double> simple_matrix::vals() const { return matrixElements; }



std::vector<double> Inverse_Gauss_Method(simple_matrix const& A, std::vector<double> const& f)
{
	std::vector<std::vector<double>> rows;
	std::vector<double> b = f, x;
	double alpha;
	for (std::size_t i = 0; i < f.size(); ++i)
	{
		rows.push_back(A.row(i));
		for (std::size_t k = 0; k < i; ++k)
		{
			for (std::size_t z = 1; rows[i][i] == 0; ++z)
			{
				rows[i] = rows[i] + rows[i - z];
				b[i] = b[i] + b[i - z];
			}
			alpha = rows[k][i] / rows[i][i];
			rows[k] = rows[k] - alpha * rows[i];
			b[k] = b[k] - b[i] * alpha;
		}
	}

	for (std::size_t k = 0; k < f.size(); ++k)
		x.push_back(b[k] / rows[k][k]);
	return x;
}


