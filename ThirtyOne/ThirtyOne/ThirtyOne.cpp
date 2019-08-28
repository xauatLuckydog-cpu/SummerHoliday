// ThirtyOne.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//leetcode 4 寻找两个有序数组中位数

	//	priority_queue<int> max;
	//	priority_queue<int, vector<int>, greater<int>> min;
	//	if (!nums1.empty())
	//		for (int i = 0; i < nums1.size(); i++) {
	//			max.push(nums1[i]);
	//			if (min.size() && max.top() > min.top()) {
	//				auto maxv = max.top(), minv = min.top();
	//				max.pop(), min.pop();
	//				max.push(minv), min.push(maxv);
	//			}
	//			if (max.size() > min.size() + 1) {
	//				min.push(max.top());
	//				max.pop();
	//			}
	//		}
	//	if(!nums2.empty())
	//		for (int i = 0; i < nums2.size(); i++) {
	//			max.push(nums2[i]);
	//			if (min.size() && max.top() > min.top()) {
	//				auto maxv = max.top(), minv = min.top();
	//				max.pop(), min.pop();
	//				max.push(minv), min.push(maxv);
	//			}
	//			if (max.size() > min.size() + 1) {
	//				min.push(max.top());
	//				max.pop();
	//			}
	//		}
	//	if(min.size() + max.size() & 1) return max.top();
	//	return (min.top() + max.top()) / 2.0;
	//}
	//bool isMatch(string s, string p) {
	//	int n = s.length(), m = p.length();
	//	vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
	//	s = " " + s;
	//	p = " " + p;
	//	f[0][0] = true;
	//	for (int i = 0; i <= n; i++)
	//		for (int j = 1; j <= m; j++) {
	//			if (i > 0 && (s[i] == p[j] || p[j] == '.'))
	//				f[i][j] = f[i][j] | f[i - 1][j - 1];
	//			if (p[j] == '*') {
	//				f[i][j] = f[i][j] | f[i][j - 2];
	//				if (i > 0 && (s[i] == p[j - 1] || p[j - 1] == '.'))
	//					f[i][j] = f[i][j] | f[i - 1][j] | f[i - 1][j - 2];
	//			}
	//		}
	//	return f[n][m];
	//}
	//int maxArea(vector<int>& height) {
	//	int res = 0;
	//	for (int i = 0, j = height.size() - 1; i < j;) {
	//		res = max(res, min(height[i], height[j]) * (j - i));
	//		if (height[i] > height[j])j--;
	//		else i++;
	//	}
	//	return res;
	//}
	//int threeSumClosest(vector<int>& nums, int target) {
	//	int ans = nums[0] + nums[1] + nums[2];
	//	sort(nums.begin(), nums.end());
	//	for (int i = 0; i < nums.size(); i++) {
	//		int l = i + 1, r = nums.size() - 1;
	//		while (l < r) {
	//			int sum = nums[i] + nums[l] + nums[r];
	//			if (abs(sum - target) < abs(ans - target))
	//				ans = sum;
	//			if (sum == target) return target;
	//			else if (sum < target) l++;
	//			else r--;
	//		}
	//	}
	//	return ans;
	//}
	//string temp[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	//vector<string> res;
	//void solve(string digits, int d, string cur) {
	//	if (d == digits.length()) {
	//		res.push_back(cur);
	//		return;
	//	}
	//	int cur_num = digits[d] - '0';
	//	for (int i = 0; i < temp[cur_num].size(); i++)
	//		solve(digits, d + 1, cur + temp[cur_num][i]);

	//}
	//vector<string> letterCombinations(string digits) {
	//	if (digits == "")
	//		return res;
	//	solve(digits, 0, "");
	//	return res;
	//}

	//ListNode* reverseKGroup(ListNode* head, int k) {
	//	ListNode* dummy = new ListNode(-1);
	//	dummy->next = head;
	//	ListNode* cur = dummy;

	//	while (cur != NULL) {
	//		ListNode* first = cur->next;
	//		ListNode* end = cur;

	//		for (int i = 0; i < k && end != NULL; i++)
	//			end = end->next;

	//		if (end == NULL)
	//			break;

	//		ListNode* pre = first;
	//		ListNode* curr = first->next;
	//		while (pre != end) {
	//			auto next = curr->next;
	//			curr->next = pre;
	//			pre = curr;
	//			curr = next;
	//		}

	//		first->next = curr;
	//		cur->next = end;
	//		cur = first;
	//	}
	//	return dummy->next;
	//}
	//int missingNumber(vector<int>& nums) {
	//	unordered_map<int,int> umap;
	//	int i;
	//	for (auto x : nums)umap[x]++;
	//	for (i = 0; i < nums.size(); i++) {
	//		umap[i]++;
	//		if (umap[i] == 1)return i;
	//	}
	//	return i + 1;
	//}
	//vector<vector<int>> res;
	//vector<int> temp;
	//int size;
	//void dfs(vector<int>& candidates, int sum, int n, int target) {
	//	if (sum == target) {
	//		res.push_back(temp);
	//		return;
	//	}
	//	if (sum > target || n == size)return;
	//	for(int i = n + 1; i < size;i++ )
	//		if (candidates[i] != candidates[n]) {
	//			dfs(candidates, sum, i, target);
	//			break;
	//		}
	//	temp.push_back(candidates[n]);
	//	dfs(candidates, sum + candidates[n], n + 1, target);
	//	temp.pop_back();
	//}

	//vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	//	sort(candidates.begin(), candidates.end());
	//	size = candidates.size();
	//	dfs(candidates, 0, 0, target);
	//	return res;
	//}

	//vector<vector<int>> res;
	//vector<int> temp;
	//int size;
	//void dfs(vector<int>& candidates, int sum, int n, int target) {
	//	if (sum == target) {
	//		res.push_back(temp);
	//		return;
	//	}
	//	if (sum > target || n == size)return;
	//	dfs(candidates, sum, n + 1, target);
	//	temp.push_back(candidates[n]);
	//	dfs(candidates, sum + candidates[n], n, target);
	//	temp.pop_back();
	//}

	//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	//	sort(candidates.begin(), candidates.end());
	//	size = candidates.size();
	//	dfs(candidates, 0, 0, target);
	//	return res;
	//}

	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int> row(9), col(9), squ(9); // 使用三个整型数组判重。
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
				if (board[i][j] < '1' || board[i][j] > '9') return false;
				int num = board[i][j] - '0';

				// 以row[i] & (1 << num)为例，这是判断第i行中，num数字是否出现过。
				// 即row[i]值的二进制表示中，第num位是否是1。
				// 以下col和squ同理。

				if ((row[i] & (1 << num)) ||
					(col[j] & (1 << num)) ||
					(squ[(i / 3) * 3 + (j / 3)] & (1 << num)))
					return false;

				row[i] |= (1 << num);
				col[j] |= (1 << num);
				squ[(i / 3) * 3 + (j / 3)] |= (1 << num);
			}
		return true;
	}

	int longestValidParentheses(string s) {
		int n = s.length();
		int start = 0, val = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')val++;
			else val--;
			if (val < 0)val = 0, start = i + 1;
			else if (val == 0)ans = max(ans, i - start + 1);
		}
		start = n - 1, val = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == ')')val++;
			else val--;
			if (val < 0)val = 0, start = i - 1;
			else if (val == 0)ans = max(ans, start - i + 1);
		}
		return ans;
	}



};




int main()
{
	string s = "mississippi";
	string p = "mis*is*p*.";
	Solution test;
	int x = 5;
    std::cout << (x |= 1 << 9);
}