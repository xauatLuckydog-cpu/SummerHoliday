// ThirtySix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (!n) return 0;
		int ans = 0;
		vector<int> l(n, 0);
		int now = 0;
		for (int i = 0; i < n; i++)
		{
			now = max(now, height[i]);
			l[i] = now;
		}
		now = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			now = max(now, height[i]);
			ans += min(l[i], now) - height[i];
		}
		return ans;
	}
	int climbStairs(int n) {
		vector<int> f(n + 1);
		f[0] = f[1] = 1;
		for (int i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
		return f[n];
	}
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		for(int i = 0; i < m; i ++)
			for(int j = 0; j < m; j ++)
				if (matrix[i][j] == 0) {
					if (i - 1 > 0)matrix[i - 1][j] = 0;
					if (j - 1 > 0)matrix[i][j - 1] = 0;
					if (i + 1 < n)matrix[i + 1][j] = 0;
					if (j + 1 < n)matrix[i][j + 1] = 0;
				}
	}
};
int main()
{
	vector<int> f = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	Solution test;
	int ans = test.trap(f);
}