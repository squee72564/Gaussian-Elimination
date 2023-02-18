#include <iostream>
#include "GaussElim.h"

void printMat(const std::vector<std::vector<float>> &mat); 
void printVec(const std::vector<float> &vec);

int main (int argc, char **argv) {
	std::vector<std::vector<float>> mat = { {3,-13,9,3},
						{-6,4,1,-18},
						{6,-2,2,4},
       						{12,-8,6,10} };
	std::vector<float> b = {-19, -34, 16, 26};
	std::vector<int> l(b.size(), 0);
	int n = mat[0].size();

	gaussianElim(n, mat, l);	
	printMat(mat);

	std::vector<float> answerVector = solve(n, mat, l, b);
	printVec(answerVector);
}

void printMat(const std::vector<std::vector<float>> &mat) {
	int n = mat.size();
	std::cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << mat[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void printVec(const std::vector<float> &vec) {
	std::cout << "\n";
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << "\t";
	}
	std::cout << "\n";
}

