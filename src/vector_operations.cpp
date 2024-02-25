#include "vector_operations.h"
#include<cmath>

double operator*(const std::vector<double>& a, const std::vector<double>& b) {
    double scalar_product = 0;
    for (int i = 0; i < a.size(); i++) {
        scalar_product += a[i] * b[i];
    }
    return scalar_product;
}


std::vector<double> operator*(const double& num, const std::vector<double>& vec) {
    std::vector<double> new_vec;
    for (int i = 0; i < vec.size(); i++) new_vec.push_back(num * vec[i]);
    return new_vec;
}


std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> sum;
    for (int i = 0; i < a.size(); i++) sum.push_back(a[i] + b[i]);
    return sum;
}

std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> sum;
    for (int i = 0; i < a.size(); i++) sum.push_back(a[i] - b[i]);
    return sum;
}


double abs(const std::vector<double>& vec) {
    return sqrt(vec * vec);
}


double sign(double a) {
    return a > 0 ? 1 : a < 0 ? -1 : 0;
}

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
    }
    std::cout << std::endl;
    return os;
}