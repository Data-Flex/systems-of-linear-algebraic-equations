#include "vector_operations.h"
#include<cmath>

double operator*(const std::vector<double>& vec, const std::vector<double>& b) {
    double scalar_product = 0;
    for (int i = 0; i < vec.size(); i++) {
        scalar_product += vec[i] * b[i];
    }
    return scalar_product;
}


std::vector<double> operator*(const double& num, const std::vector<double>& vec) {
    std::vector<double> new_vec;
    for (int i = 0; i < vec.size(); i++) new_vec.push_back(num * vec[i]);
    return new_vec;
}


std::vector<double> operator+(const std::vector<double>& vec, const std::vector<double>& b) {
    std::vector<double> sum;
    for (int i = 0; i < vec.size(); i++) sum.push_back(vec[i] + b[i]);
    return sum;
}

std::vector<double> operator-(const std::vector<double>& vec, const std::vector<double>& b) {
    std::vector<double> sum;
    for (int i = 0; i < vec.size(); i++) sum.push_back(vec[i] - b[i]);
    return sum;
}


std::vector<double> operator/(const std::vector<double>& vec, const double& num) {
    std::vector<double> new_vec;
    for (int i = 0; i < vec.size(); i++) new_vec.push_back(vec[i]/num);
    return new_vec;
}



double abs(const std::vector<double>& vec) {
    return sqrt(vec * vec);
}


double sign(double a) {
    return a > 0 ? 1 : a < 0 ? -1 : 0;
}

double max(std::vector<double> const& v) {
    double max = abs(v[0]);
    for (int i = 0; i < v.size(); ++i)
        if (max < abs(v[i])) max = abs(v[i]);
    return max;
}

int max(std::vector<int> const& v) {
    int max = abs(v[0]);
    for (int i = 0; i < v.size(); ++i)
        if (max < abs(v[i])) max = abs(v[i]);
    return max;
}

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
    }
    std::cout << std::endl;
    return os;
}

std::vector<double> givens_rots(std::vector<double> const& h, std::vector<std::pair<double, double>> const& rots)
{
    std::vector<double> res = h;
    std::vector<double> resi = std::vector<double>(2);
    for (std::size_t i = 0; i < h.size() - 1; ++i)
    {
        resi[0] = rots[i].first * res[i] - rots[i].second * res[i + 1];
        resi[1] = rots[i].second * res[i] + rots[i].first * res[i + 1];
        res[i] = resi[0];
        res[i + 1] = resi[1];
    }
    return res;
}