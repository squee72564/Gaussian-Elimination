#include "GaussElim.h"

void printMat(const std::vector<std::vector<float>> &mat) {
	int n = mat.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << mat[i][j] << "\t";
		}
		std::cout << "\n";
	}
}


void gaussianElim(const int n, std::vector<std::vector<float>>& mat) {
	std::vector<int> l(n, 0);
	std::vector<float> s(n, 0);

	int i = 0;
	int j = 0;
	int k = 0;
	float smax = 0;
	float rmax = 0;
	float xmult = 0;
	float r = 0;

	for (i = 0; i < n; i++) {
		l[i] = i;
		smax = 0;
		for (j = 0; j < n; j++) {
			smax = std::max(smax, mat[i][j]);
		}
		s[i] = float(smax);
	}

	for (k = 0; k < n-1; k++ ) {
		rmax = 0;
		for (i = k; i < n; i++) {
			r = std::abs(mat[l[i]][k] / s[l[i]]);
			if (r > rmax) {
				rmax = r;
				j = i;
			}	
		}
		
		int temp = l[i-1];
		l[i-1] = l[k];
		l[k] = temp;

		for (i = k+1; i < n; i++) {
			xmult = float(mat[l[i]][k] / mat[l[k]][k]);
			mat[l[i]][k] = xmult;
			for (j = k+1; j < n; j++) {
				mat[l[i]][j] = mat[l[i]][j]-(xmult*mat[l[k]][j]);
			}
		}
	}
}
