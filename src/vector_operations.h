#pragma once
#include <vector>
#include <iostream>

double operator*(const std::vector<double>& a, const std::vector<double>& b);


std::vector<double> operator*(const double& num, const std::vector<double>& vec);


std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b);


std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec);
