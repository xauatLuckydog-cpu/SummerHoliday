// DayTwentySix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;


class Solution {
public:

	vector<int> maxInWindows2(vector<int>& nums, int k) {
		vector<int> rst;
		deque<int> dq;
		for (int i = 0; i < nums.size(); i++)
		{
			while (dq.size() && dq.front() <= i - k) dq.pop_front();
			while (dq.size() && nums[dq.back()] <= nums[i]) dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1)rst.push_back(nums[dq.front()]);
		}
		return rst;
	}
	queue<int> q;
	vector<int> res;
	int k;
	void sovel(queue<int>& q)
	{
		int ans = 0;
		while (k--) {
			int t = q.front();
			ans = max(ans,t);
			q.pop();
			q.push(t);
		}
		res.push_back(ans);
	}
	vector<int> maxInWindows(vector<int>& nums, int _k) {
		
		for (int i = 0; i < nums.size(); i++) {
			if (q.size() < _k)q.push(nums[i]);
			if (q.size() == _k) {
				k = _k;
				sovel(q);
				q.pop();
			}
		}
		return res;
	}
};

int main()
{
	vector<int> vec = { 2,3,4,2,6,2,5,1 };
	Solution test;
	test.maxInWindows(vec, 3);
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
