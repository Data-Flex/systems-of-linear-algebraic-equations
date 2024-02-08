#include "progonka.h"
#include <iostream>

std::vector<double> progonka(const three_diag_table& table, const std::vector<double>& d) {
	int n = d.size() - 1;
	std::vector<double> x, p, q;
	x.resize(n + 1); p.resize(n + 1); q.resize(n + 1);
	p[1] = -table.c[0] / table.b[0];
	q[1] = d[0] / table.b[0];
	for (int i = 1; i < n; i++) {

		p[i + 1] = -table.c[i] / (table.a[i - 1] * p[i] + table.b[i]);
		q[i + 1] = (d[i] - table.a[i - 1] * q[i]) / (table.a[i - 1] * p[i] + table.b[i]);
	}
	

	x[n] = (d[n] - table.a[n - 1] * q[n]) / (table.a[n - 1] * p[n] + table.b[n]);
	for (int i = n; i > 0; i--) {
	
		x[i - 1] = x[i] * p[i] + q[i];
	}

	return x;

}

