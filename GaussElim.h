#ifndef GUASS_ELIM
#define GUASS_ELIM

#include <vector>
#include <algorithm>
#include <iostream>


void gaussianElim(const int n, std::vector<std::vector<float>>& mat, std::vector<int>& l);
std::vector<float> solve(int n, const std::vector<std::vector<float>> &mat, const std::vector<int> &l, std::vector<float> &b);

#endif
