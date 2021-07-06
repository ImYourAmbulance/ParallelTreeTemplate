#include <string>
#include <chrono>
#include "functions.h"


int main() {
	std::ifstream testfile("testfile.txt");

	std::ofstream result("result.txt");

	std::string tmp_str;

	while (std::getline(testfile, tmp_str)) {
		int size = 0;
		Node* root = MakeBinaryTree(tmp_str, size);

		bool* arr_bool = new bool[size];
		auto start = std::chrono::high_resolution_clock::now();

		ProcessBinaryStrings(arr_bool, 0, size, root, result);


		auto finish = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> elapsed = finish - start;
		result << "Elapsed time: " << elapsed.count() << std::endl;
		result << "____________________________________________________________________" << std::endl;
	}
	
	testfile.close();
	result.close();
	
	return 0;
}