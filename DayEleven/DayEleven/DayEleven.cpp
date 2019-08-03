// DayEleven.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:

	int divide(int dividend, int divisor)
	{
		long long max = 2147483647, min = -2147483647;
		long long x = dividend, y = divisor;
		if (y == 0)
			return INT_MAX;
		if (y == 1)
			return dividend;
		bool flag;
		if (x > 0 && y > 0 || x < 0 && y < 0)
			flag = true;
		else
			flag = false;
		x = abs(x); y = abs(y);
		long long ans = 0;

		int l = 0, r = dividend;
		while (l < r) {
			int mid = l + r >> 1;
			if (mid <= divisor)r = mid;
			else l = mid + 1;
		}
		if (flag == false)
			ans = -l;
		if (ans < min || ans >max)
			return INT_MAX;
		return int(ans);

	}

	/*int divide(int dividend, int divisor) {
		long long max = 2147483647,min = -2147483647;
		long long x = dividend, y = divisor;
		if (y == 0)
			return INT_MAX;
		bool flag;
		if (x > 0 && y > 0 || x < 0 && y < 0)
			flag = true;
		else
			flag = false;
		x = abs(x); y = abs(y);
		long long ans = 0;
		while (x >= y) {
			x -= y;
			ans++;
		}
		if (flag == false)
			ans = -ans;
		if (ans < min || ans >max)
			return INT_MAX;
		return int(ans);
	}*/
};

int n, m;
vector<int> path;

void dfs(int u, int state)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (state >> i & 1) {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
		return;
	}

	dfs(u + 1, state);
	dfs(u + 1, state | 1 << u);
}

void dfs(int u, int sum, int state)
{
	if (sum + n - u < m)return;
	if (sum == m)
	{
		for (int i = 0; i < n; i++)
			if (state >> i & 1)
				cout << i + 1 << " ";
		cout << endl;
		return;
	}

	if (u == n)return;

	dfs(u + 1, sum + 1, state | 1 << u);
	dfs(u + 1, sum, state);
}

//void dfs(int u, int state)
//{
//	if (u == n)
//	{
//		for (auto x : path)cout << x << "";
//		cout << endl;
//		return;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (!(state >> i & 1))
//		{
//			path.push_back(i + 1);
//			dfs(u + 1, state | (1 << i));
//			path.pop_back();
//		}
//	}
//}


int main()
{
	unordered_set<int,int> st;
	vector<int> vc;
	vc.
	st.insert(20);
	st.insert(20);
}