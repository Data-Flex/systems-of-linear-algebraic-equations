#include"CSR.h"
#include<iostream>
#include"vector_operations.h"
#include<fstream>
#include<chrono>
#include <numbers>


int main() {
	std::vector<double> A = { 0.09, 0.18, 0, 0.18, 0.54, 0.09, 0, 0.09, 0.9 };
	simple_matrix S(A, 3);
	CSR M(S);
	std::vector<double> x0 = { 0, 0, 0 };
	std::vector<double> b = { 100, 150, 200 };

	std::ofstream file_time, file_error, file_iter;

	file_time.open("../time_test_results/0_time.txt");
	file_error.open("../time_test_results/0_error.txt");
	file_iter.open("../time_test_results/0_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.MPI(b, x0, i, 1e-20);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/1_time.txt");
	file_error.open("../time_test_results/1_error.txt");
	file_iter.open("../time_test_results/1_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.Jacobi(b, x0, i, 1e-20);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/2_time.txt");
	file_error.open("../time_test_results/2_error.txt");
	file_iter.open("../time_test_results/2_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.GS(b, x0, i, 1e-20);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/3_time.txt");
	file_error.open("../time_test_results/3_error.txt");
	file_iter.open("../time_test_results/3_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.gradient_descent(b, x0, i, 1e-20);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/4_time.txt");
	file_error.open("../time_test_results/4_error.txt");
	file_iter.open("../time_test_results/4_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.cheb_MPI(b, x0, i, 1e-20, 0.9);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/5_time.txt");
	file_error.open("../time_test_results/5_error.txt");
	file_iter.open("../time_test_results/5_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.cheb_Jacobi(b, x0, i, 1e-20, 0.9);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/6_time.txt");
	file_error.open("../time_test_results/6_error.txt");
	file_iter.open("../time_test_results/6_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.cheb_GS(b, x0, i, 1e-20, 0.9);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/7_time.txt");
	file_error.open("../time_test_results/7_error.txt");
	file_iter.open("../time_test_results/7_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.cheb_gradient_descent(b, x0, i, 1e-20, 0.9);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/8_time.txt");
	file_error.open("../time_test_results/8_error.txt");
	file_iter.open("../time_test_results/8_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.simmetrical_GS(b, x0, i, 1e-20);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
	//----------------------------------------------------------------------------------------------
	//file_time.open("../time_test_results/9_time.txt");
	//file_error.open("../time_test_results/9_error.txt");
	//file_iter.open("../time_test_results/9_iter.txt");
	//for (int i = 1; i < 1000; i++) {
	//	std::cout << i << "\n";
	//	auto start = std::chrono::high_resolution_clock::now();
	//	std::cout << "we ok" << "\n";
	//	std::vector<double> res = M.cheb_simmetrical_GS(b, x0, i, 1e-20, 0.9);
	//	std::cout << "we ok" << "\n";
	//	auto end = std::chrono::high_resolution_clock::now();
	//	std::cout << "we ok" << "\n";
	//	double error = abs(M * res - b);
	//	std::cout << "we ok" << "\n";
	//	auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	//	file_time << time << "\n";
	//	file_error << std::log(error) << "\n";
	//	file_iter << i << "\n";
	//}
	//std::cout << "we ok" << "\n";
	//file_time.close();
	//file_error.close();
	//file_iter.close();
	//std::cout << "we ok" << "\n";
	/*file_time.open("../time_test_results/9_time.txt");
	file_error.open("../time_test_results/9_error.txt");
	file_iter.open("../time_test_results/9_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.conjurate_gradient(b, x0, i, 1e-20);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();*/
	//----------------------------------------------------------------------------------------------
	file_time.open("../time_test_results/10_time.txt");
	file_error.open("../time_test_results/10_error.txt");
	file_iter.open("../time_test_results/10_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.GMRES(b, x0, 3, i, 0.1);
		auto end = std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time << time << "\n";
		file_error << std::log(error) << "\n";
		file_iter << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
}