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


std::vector<double> CSR::MPI(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	double tay = 1/((*this).lambda_max()+1);
	std::vector <double> res = x0;
	for (int i = 0; i < Nmax; i++) {
		res = res - tay * ((*this) * res - b);
		if (not (abs((*this) * res - b) >= Tol)) { break; }
	}
	return res;
}

std::vector<double> CSR::gradient_descent(	const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	double tay = 0;
	std::vector <double> res = x0;
	for (int i = 0; i < Nmax; i++) {
		std::vector<double> r = (*this) * res - b;
		tay = (r * r) / (r*((*this)*r));
		res = res - tay * ((*this) * res - b);
		if (not (abs((*this) * res - b) >= Tol)) { break; }
	}
	return res;
}

std::vector<double> CSR::Jacobi(			const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
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
		if (not (abs((*this) * res - b) >= Tol)) { break; }
	}
	return res;
}

std::vector<double> CSR::GS(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
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
		if (not (abs((*this) * x - b) >= Tol)) { break; }
	}
	return x;
}


std::vector<double> CSR::Cheb_accel(		const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double lambd_min, const double lambd_max) {
	std::vector<int> order = { 0, 7, 3, 4, 1, 6, 2, 5 };
	double pi = 3.14159265358979323846;
	int n = 8;
	std::vector<double> res = x0;
	for (int i = 0; i < Nmax; i++) {
		double tay = 1 / ((lambd_max + lambd_min) / 2 + (lambd_max - lambd_min) / 2 * std::cos(pi * (2 * order[i%8] + 1) / (2 * n)));
		res = res - tay * ((*this)*res - b);
		if (not (abs((*this) * res - b) >= Tol)) { break; }
	}
	return res;
}


std::vector<double> CSR::simmetrical_GS(	const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol) {
	std::vector<double> x = x0;
	double d = 0;
	//double sum = 0;;
	for (int N = 0; N < Nmax; N++) {
		for (int i = 0; i < x.size()/*nonzero.size() - 1*/; i++) {
			x[i] = b[i];
			d = 0;
			//sum = 0;
			for (int k = nonzero[i]; k < nonzero[i + 1]; k++) {
				if (i != columns[k]) {
					//sum += elements[k] * x[columns[k]];
					x[i] -= elements[k] * x[columns[k]];
				}
				else {
					d = elements[k];
				}
			}
			//x[i] = (b[i] - sum) / d;
			x[i] /= d;
		}
		for (int i = nonzero.size() - 1; i >= 0; i--) {
			d = 0;
			//sum = 0;
			x[i] = b[i];
			for (int k = nonzero[i]; k < nonzero[i + 1]; k++) {
				if (i != columns[k]) {
					//sum += elements[k] * x[columns[k]];
					x[i] -= elements[k] * x[columns[k]];
				}
				else {
					d = elements[k];
				}
			}
			//x[i] = (x[i] - sum) / d;
			x[i] /= d;
		}
		if (abs((*this) * x - b) < Tol) { break; }
		
	}
	return x;
}












std::vector<double> CSR::cheb_MPI(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p) {
	std::vector <double> res = x0;
	res = this->MPI(b, res, 1, Tol);
	double mu_0 = 1, mu_1 = p, mu_next;
	for (std::size_t it = 0; it < Nmax; ++it)
	{
		mu_next = mu_1;
		mu_1 = 2 / p * mu_1 - mu_0;

		res = 2 * mu_next / (p * mu_1) * this->MPI(b, res, 1, Tol) - mu_0 / mu_1 * res;

		if (not (abs((*this) * res - b) >= Tol)) break;
		mu_0 = mu_next;
	}
	return res;
}
std::vector<double> CSR::cheb_Jacobi(			const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p) {
	std::vector <double> res = x0;
	res = this->Jacobi(b, res, 1, Tol);
	double mu_0 = 1, mu_1 = p, mu_next;
	for (std::size_t it = 0; it < Nmax; ++it)
	{
		mu_next = mu_1;
		mu_1 = 2 / p * mu_1 - mu_0;

		res = 2 * mu_next / (p * mu_1) * this->Jacobi(b, res, 1, Tol) - mu_0 / mu_1 * res;

		if (not (abs((*this) * res - b) >= Tol)) break;
		mu_0 = mu_next;
	}
	return res;
}
std::vector<double> CSR::cheb_GS(				const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p) {
	std::vector <double> res = x0;
	res = this->GS(b, res, 1, Tol);
	double mu_0 = 1, mu_1 = p, mu_next;
	for (std::size_t it = 0; it < Nmax; ++it)
	{
		mu_next = mu_1;
		mu_1 = 2 / p * mu_1 - mu_0;

		res = 2 * mu_next / (p * mu_1) * this->GS(b, res, 1, Tol) - mu_0 / mu_1 * res;

		if (not (abs((*this) * res - b) >= Tol)) break;
		mu_0 = mu_next;
	}
	return res;
}
std::vector<double> CSR::cheb_simmetrical_GS(	const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p) {
	std::vector <double> res = x0;
	std::cout << "cheb ok" << "\n";
	res = this->simmetrical_GS(b, res, 1, Tol);
	double mu_0 = 1, mu_1 = p, mu_next;
	for (int i = 0; i  < Nmax; i++)
	{	
		mu_next = mu_1;
		mu_1 = 2 / p * mu_1 - mu_0;
		std::cout << i << "\n";
		res = 2 * mu_next / (p * mu_1) * (this->simmetrical_GS(b, res, 1, Tol)) - mu_0 / mu_1 * res;
		std::cout << i << "\n";
		if (abs((*this) * res - b) < Tol) break;
		mu_0 = mu_next;
	}
	return res;
}
std::vector<double> CSR::cheb_gradient_descent(	const std::vector <double>& b, const std::vector <double>& x0, const int Nmax, const double Tol, const double p) {
	std::vector <double> res = x0;
	res = this->gradient_descent(b, res, 1, Tol);
	double mu_0 = 1, mu_1 = p, mu_next;
	for (std::size_t it = 0; it < Nmax; ++it)
	{
		mu_next = mu_1;
		mu_1 = 2 / p * mu_1 - mu_0;

		res = 2 * mu_next / (p * mu_1) * this->gradient_descent(b, res, 1, Tol) - mu_0 / mu_1 * res;

		if (not (abs((*this) * res - b) >= Tol)) break;
		mu_0 = mu_next;
	}
	return res;
}





std::vector<double> CSR::conjurate_gradient(const std::vector<double>& b, const std::vector<double>& x0, const int Nmax, const double Tol) {
	std::vector<double> current = x0;
	std::vector<double> discrepancy = (*this)*current - b;
	std::vector<double> orth = discrepancy;
	for (size_t n = 0; n < Nmax; n++) {
		double alpha = (orth * discrepancy) / (orth * ((*this) * orth));
		current = current - alpha * orth;
		std::vector <double> discrepancy1 = (*this) * current - b;
		if (orth * orth == 0)
			return current;
		double beta = (discrepancy1 * discrepancy1) / (orth * discrepancy);
		discrepancy = discrepancy1;
		orth = discrepancy + beta * orth;

		if (not (abs((*this) * current - b) >= Tol)) { break; }
	}
	return current;
}





std::vector<double> CSR::GMRES(const std::vector<double>& b, const std::vector<double>& x0, int const& m, const int Nmax, const double Tol)
{
	std::vector<double> r0, x, x0_, vk, h, h_rots, y, by;                                
	std::vector<std::pair<double, double>> giv_rots;
	x = x0;
	for (std::size_t it = 0; it < Nmax; ++it)
	{
		x0_ = x;
		r0 = (*this)*x0_ - b;
		simple_matrix V(r0 / abs(r0), 1);

		simple_matrix H({}, 0);
		giv_rots = std::vector<std::pair<double, double>>(0);

		for (std::size_t k = 1; k <= m; ++k)
		{
			vk = (*this) * V.col(k - 1);
			h = std::vector<double>(k + 1);
			for (std::size_t i = 0; i < k; ++i)
			{
				h[i] = ((*this) * V.col(k - 1)) * (V.col(i));
				vk = vk - h[i] * V.col(i);
			}
			h[k] = abs(vk);
			vk = vk / h[k];

			h_rots = { h[k - 1], h[k] };
			giv_rots.push_back(std::make_pair(h_rots[0] / abs(h_rots), (-1) * h_rots[1] / abs(h_rots)));

			h = givens_rots(h, giv_rots);
			h.pop_back();

			H = add_col_H(H, h);

			by = std::vector<double>(k);
			by[0] = abs(r0);
			for (std::size_t i = 1; i < k; ++i) by[i] = 0;

			std::reverse(giv_rots.begin(), giv_rots.end());
			by = givens_rots(by, giv_rots);

			y = Inverse_Gauss_Method(H, (-1.) * by);

			x = x0_ + V * y;
			if (not (abs((*this) * x - b) >= Tol)) { break; }

			V = add_col(V, vk);
		}
	}
	return x;
}