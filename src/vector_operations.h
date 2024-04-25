#pragma once
#include <vector>
#include <iostream>

double operator*(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator*(const double& num, const std::vector<double>& vec);
std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator/(const std::vector<double>& a, const double& num);


double abs(const std::vector<double>& vec);
double sign(double a);
double max(std::vector<double> const& v);
int max(std::vector<int> const& v);

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec);

std::vector<double> givens_rots(std::vector<double> const& h, std::vector<std::pair<double, double>> const& rots);
