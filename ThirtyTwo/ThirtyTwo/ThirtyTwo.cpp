// ThirtyTwo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int size;
	vector<int> temp;
	vector<bool> st;
	vector<vector<int>> res;
	void permuteDfs(vector<int>& nums,int n) {
		if (n == size) {
			res.push_back(temp);
			return;
		}
		for (int i = 0; i < size; i++) {
			if (!st[i]) {
				st[i] = true;
				temp.push_back(nums[i]);
				permuteDfs(nums, n + 1);
				st[i] = false;
				temp.pop_back();
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		size = nums.size();
		for (int i = 0; i < size; i++) st.push_back(false);
		permuteDfs(nums, 0);
		return res;
	}
	
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>>ans;
		vector<vector<int>>rst;
		sort(nums.begin(), nums.end());
		do {
			ans.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		unordered_map <vector<int>, int> mp;
		for (auto x : ans)mp[x]++;
		for (auto x : mp)rst.push_back(x.first);
		return rst;
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
