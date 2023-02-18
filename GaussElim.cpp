#include "GaussElim.h"

void gaussianElim(const int n, std::vector<std::vector<float>>& mat, std::vector<int>& l) {
	std::vector<float> s(n, 0);

	int i = 0;
	int j = 0;
	int k = 0;
	float smax = 0.0f;
	float rmax = 0.0f;
	float xmult = 0.0f;
	float r = 0.0f;

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
		
		int temp = l[j];
		l[j] = l[k];
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


std::vector<float> solve(int n, const std::vector<std::vector<float>> &mat, const std::vector<int> &l, std::vector<float> &b) {

	std::vector<float> x(n, 0);
	
	int i = 0;
	int k = 0;
	int j = 0;
	float sum = 0.0f;

	for (k = 1; k < n-1; k++) {
		for (i = k+1; i < n; i++ ) {
			b[l[i]] = b[l[i]] - mat[l[i]][k]*b[l[k]];	
		}
	}
	
	x[n-1] = b[l[n-1]] / mat[l[n-1]][n-1];

	for (i = n-1; i>=0; i--) {
		sum = b[l[i]];
		for (j = i+1; j < n; j++) {
			sum = sum - mat[l[i]][j]*x[j];
		}
		x[i] = sum / mat[l[i]][i];
	}

	return x;
}
