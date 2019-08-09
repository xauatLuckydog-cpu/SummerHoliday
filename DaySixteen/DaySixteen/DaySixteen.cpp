// DaySixteen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		vector<int> temp;
		sort(intervals.begin(), intervals.end());
		int cur = 0;
		int next = 1;
		int len = intervals.size();
		while (cur < len - 1)
		{
			//融合
			if (intervals[cur][1] >= intervals[next][0])
			{
				intervals[next][0] = intervals[cur][0];
				//标记cur已经被融合，不需要加入到结果中
				intervals[cur][0] = INT_MAX;
				if (intervals[cur][1] > intervals[next][1])
				{
					intervals[next][1] = intervals[cur][1];
				}
			}
			next++;
			cur++;
		}
		for (int i = 0; i < len; i++)
		{
			if (intervals[i][0] != INT_MAX)
			{
				res.push_back(intervals[i]);
			}
		}
		return res;
	}

	void sortColors(vector<int>& nums) {
		int color[3] = { 0 };
		for (int i = 0; i < nums.size(); i++)
		{
			color[nums[i]]++;
		}
		nums.clear();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < color[i]; j++)
			{
				nums.push_back(i);
			}

		}
	}
};

long long res[67][67] = { 0 };
long long C(long long n, long long m)
{
	if (m == 0 || m == n)return 1;
	if (res[n][m] != 0)return res[n][m];
	return res[n][m] = C(n - 1, m) + C(n - 1, m - 1);
}

void bubble_sort(vector<int>& q){
	for (int i = q.size() - 1; i > 0; i--)
	{
		bool flag = false; //是否交换过
		for (int j = 0; j + 1 <= i; j++)
		{
			if (q[j] > q[j + 1])swap(q[j], q[j + 1]), flag = true;
		}
		if (!flag) break;
	}
		
}

void selection_sort(vector<int>& q) {
	for (int i = 0; i < q.size(); i++){
		for (int j = i + 1; j < q.size(); j++)
			if (q[i] > q[j])swap(q[i], q[j]);
	}
}


int main()
{

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
