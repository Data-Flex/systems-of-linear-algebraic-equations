#pragma once
#include"simple_matrix.h"
#include"vector_operations.h"

simple_matrix P(const simple_matrix& mtr, const std::vector<double>& nu);

std::pair<simple_matrix, simple_matrix> householder(const simple_matrix& mtr);

std::vector<double> householder_solve(const simple_matrix& A, const std::vector<double>& f);