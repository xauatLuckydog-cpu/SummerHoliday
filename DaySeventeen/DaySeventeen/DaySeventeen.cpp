// DaySeventeen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long ans = 0;
		bool isminus = false;
		for (int i = 0; i < str.length(); i++)
		{
			if(ans==0&&str[i])
			if (ans > INT_MAX)return INT_MAX;
			if (str[i] == '-')isminus = true;
			if (str[i] >= '0' && str[i] <= '9')ans = ans * 10 + (int)(str[i]-'0');
		}
		if (isminus)ans = -ans;
		if (ans < INT_MIN)return INT_MIN;
		return ans;
	}


	string intToRoman(int num) {
		int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string reps[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string res;
		for (int i = 0; i < 13; i++)
			while (num >= values[i])
			{
				num -= values[i];
				res += reps[i];
			}
		return res;
	}
};

class Solution2 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();

		for (int i = 0; i < n; i++)
		{
			if (nums[abs(n) - 1] > 0) {
				nums[abs(n) - 1] *= -1;
			}
			else res.push_back(abs(n));
				
		}
		return res;
	}
};

const int N = 1010;

int n, m;
int f[N][N];
int ff[N];
int v[N], w[N];

int main()
{
	Solution test;
	test.myAtoi("words and 987");
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int v, w;
		cin >> v >> w;
		for (int j = v; j <= m; j++)
		{
			ff[j] = max(ff[j], ff[j - v] + w);
		}
		cout << ff[m] << endl;
		
	}
	//v[i]表示第i件物品的体积 w[i]表示第i件物品的价值
	//n是物品数量 m是背包的容积
	//for (int i = 1; i <= n; i++)cin >> v[i] >> w[i];

	for(int i = 1;i <= n;i ++)
		for (int j = 0; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];//将上一步装好的背包转移到下一个背包里面
			if (j >= v[i])//判断是否还能装下当前物品
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);//装下之后
		}
	int res = 0;
	for (int i = 0; i <= m; i++)res = max(res, f[n][i]);
	cout << res << endl;
	return 0;
}