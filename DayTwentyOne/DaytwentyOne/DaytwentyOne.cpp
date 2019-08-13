// DaytwentyOne.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;


vector<int> mul(vector<int> a, int b)
{
	vector<int> c;
	int t = 0;
	for (int i = 0; i < a.size(); i++)
	{
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while (t) c.push_back(t % 10), t /= 10;
	return c;

}
vector<int> div(vector<int> a, int b)
{
	vector<int> c;
	bool is_first = false;
	for (int i = a.size() - 1, t = 0; i >= 0; i--)
	{
		t = t * 10 + a[i];
		int x = t / b;
		if (x || is_first)
		{
			is_first = true;
			c.push_back(x);
		}
		t %= b;
	}
	return vector<int>(c.rbegin(), c.rend());
}

vector<int> max_vec(vector<int> a, vector<int> b)
{
	if (a.size() > b.size()) return a;
	if (a.size() < b.size()) return b;
	if (a.size() == b.size())
	{
		return vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend()) ? a : b;
	}
}

int main()
{
	string res = {"hujiajun"};
	vector<int> vec;
	vec.push_back(2);
	try
	{
		vec.at(3);
	}
	catch (const std::exception&)
	{
		cout << "超出限制";
	}
	reverse(res.begin(), res.end());

	if (is_sorted(res.begin(), res.end()))
	{
		cout << "no";
	};
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());

	if (is_sorted(res.begin(), res.end()))
	{
		cout << "yes";
	};
    std::cout << "Hello World!\n"; 
}