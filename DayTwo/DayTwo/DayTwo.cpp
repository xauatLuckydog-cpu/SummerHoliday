﻿#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;

		int n = matrix.size(), m = matrix[0].size();
		int l = 0, r = n * m + 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (matrix[mid / m][mid % m] >= target) r = mid;
			else l = mid + 1;
		}
		if (matrix[r / m][r % m] != target) return false;
		return true;
	}
};

int main()
{
	int i = 1;
	int j = i++ + ++i;
	std::cout << j;
}	

