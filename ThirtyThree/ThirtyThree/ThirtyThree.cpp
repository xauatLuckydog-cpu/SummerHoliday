// ThirtyThree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> temp;
		int res = 0;
		for (int i = num2.size(); i >= 0; i--) {
			int sum = 0;
			int c = 1, carry = 0;
			for (int j = num1.size(); j >= 0; j--) {
				c = c * num2[i] * num1[j] + carry;
				sum = sum * 10 + c % 10;
				carry = c / 10;
				c = 1;
			}
			temp.push_back(sum);
		}
		for (auto x : temp) res += x;
		return to_string(res);
	}
	vector<int> sortArrayByParityII(vector<int>& A) {
		int n = A.size();
		vector<int> res(n),ji(n/2),ou(n/2);
		for (auto x : A)
			if (x % 2 == 0)ou.push_back(x);
			else
			{
				ji.push_back(x);
			}
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				res[i] = ou.back();
				ou.pop_back();
			}
			else {
				res[i] = ji.back();
				ji.pop_back();
			}
		}
		return res;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
