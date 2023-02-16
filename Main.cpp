#include <iostream>
#include "GaussElim.h"

int main (int argc, char **argv) {
	std::vector<std::vector<float>> mat = {{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
	int n = mat[0].size();
	gaussianElim(n, mat);	
}
