// DayTen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;


const int N = 200;
int ans[N] = { 0 };
int count_ans = 0;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> hash;
		int res = 0;
		for (int i = 0, j = 0; j < s.size(); j++)
		{
			if (++hash[s[j]] > 1)
			{
				while (i < j)
				{
					hash[s[i]]--;
					i++;
					if (hash[s[j]] == 1) break;
				}
			}
			res = max(res, j - i + 1);
		}
		return res;
	}

	int qmi(int m, int k, int p)
	{
		int res = 1, t = m;
		while (k)
		{
			if (k & 1) res = res * t % p;
			t = t * t % p;
			k >>= 1;
		}
		return res;
	}


};


void dfs(int &n)
{
	if (n == 1) return;
	else if (n % 2 == 0)
	{
		count_ans += 1;
		n /= 2;
		dfs(n);
	}
	else if (n % 2 != 0) 
	{
		count_ans += 1;
		n = (3 * n + 1) / 2;
		dfs(n);
	}
}

bool JudgeRe(string s)
{
	int n = s.length();
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - i - 1])return false;

	}
	return true;
}

int main()
{
	Solution test;
	test.qmi(2, 3, 3);
}