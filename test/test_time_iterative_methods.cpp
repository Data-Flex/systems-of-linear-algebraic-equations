#include"CSR.h"
#include<iostream>
#include"vector_operations.h"
#include<fstream>
#include<chrono>


int main() {
	std::vector<double> A = {	5, 2, 0, 2,
								2, 9 ,5, 1,
								0, 5, 8, 0,
								2, 1, 0, 3 };
	simple_matrix S(A, 4);
	CSR M(S);
	std::vector<double> correct = { 1, 1, 1, 1 };
	std::vector<double> x0 = { 10, 10, 10, 10 };
	std::vector<double> b = M * correct;

	std::ofstream file_time, file_error, file_iter;
	
	file_time.open( "../time_test_results/MPI_time.txt");
	file_error.open("../time_test_results/MPI_error.txt");
	file_iter.open( "../time_test_results/MPI_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.MPI(b, x0, i, 0);
		auto end =	 std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time  << time  << "\n";
		file_error << error << "\n";
		file_iter  << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();


	file_time.open(	"../time_test_results/Cheb_time.txt");
	file_error.open("../time_test_results/Cheb_error.txt");
	file_iter.open( "../time_test_results/Cheb_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.Cheb_accel(b, x0, i, 0, 0, M.lambda_max()+1);
		auto end =   std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time  << time  << "\n";
		file_error << error << "\n";
		file_iter  << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();


	file_time.open(	"../time_test_results/Jacobi_time.txt");
	file_error.open("../time_test_results/Jacobi_error.txt");
	file_iter.open( "../time_test_results/Jacobi_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.Jacobi(b, x0, i, 0);
		auto end =   std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time  << time  << "\n";
		file_error << error << "\n";
		file_iter  << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();


	file_time.open(	"../time_test_results/GS_time.txt");
	file_error.open("../time_test_results/GS_error.txt");
	file_iter.open( "../time_test_results/GS_iter.txt");
	for (int i = 1; i < 1000; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> res = M.GS(b, x0, i, 0);
		auto end =   std::chrono::high_resolution_clock::now();
		double error = abs(M * res - b);
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		file_time  << time  << "\n";
		file_error << error << "\n";
		file_iter  << i << "\n";
	}
	file_time.close();
	file_error.close();
	file_iter.close();
}