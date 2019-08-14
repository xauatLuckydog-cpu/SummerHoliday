#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution
{
public:

	int get_single_sum(int x)
	{
		int s = 0;
		while (x) s += x % 10, x / 10;
		return s;
	}

	int get_sum(pair<int, int> p)
	{
		return get_single_sum(p.first) + get_single_sum(p.second);
	}
	int movingCount(int threshold, int rows, int cols)
	{
		int res = 0;
		if (!rows || !cols) return 0;

		vector<vector<bool>> st(rows, vector<bool>(cols));
		queue<pair<int, int>> q;

		q.push({ 0,0 });
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

		while (q.size()) {
			auto t = q.front();
			q.pop();

			if (get_sum(t) > threshold || st[t.first][t.second]) continue;
			res++;
			st[t.first][t.second] = true;

			for (int i = 0; i < 4; i++)
			{
				int x = t.first + dx[i], y = t.second + dy[i];
				if (x >= 0 && x < rows && y >= 0 && y < cols) {
					q.push({ x,y });
				}
			}
		}
		return res;
	}

	ListNode* reverseList(ListNode* head)
	{
		ListNode* pre = nullptr;
		auto cur = head;
		while (cur) {
			auto next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}

	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		auto dummy = new ListNode(-1);
		auto cur = dummy;
		while (l1 && l2)
		{
			if (l1->val < l2->val) {
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
		}
		if (l1) cur->next = l1;
		else cur->next = l2;
		return dummy->next;
	}

	bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot1 || !pRoot2) return false;
		if (isPart(pRoot1, pRoot2))return true;
		return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
	}

	bool isPart(TreeNode* p1, TreeNode* p2) {
		if (!p2) return true;
		if (!p1 || p1->val != p2->val) return false;
		return isPart(p1->left, p2->left) && isPart(p1->right, p2->right);
	}

	void mirror(TreeNode* root) {
		if (!root) return;
		mirror(root->left);
		mirror(root->right);
		swap(root->left, root->right);
	}

	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return dfs(root->left, root->right);
	}
	bool dfs(TreeNode* p, TreeNode* q) {
		if (!p || !q) return !p && !q;
		if (p->val != q->val)return false;
		return dfs(p->left, q->right) && dfs(p->right, q->left);
	}

	vector<int> printMatrix(vector<vector<int>> matrix) {
		vector<int> res;
		int n = matrix.size();
		if (!n) return res;
		int m = matrix[0].size();

		vector<vector<bool>> st(n, vector<bool>(m, false));
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//左 上 右 下
		int x = 0, y = 0, d = 0;
		for (int i = 0; i < n * m; i++)
		{
			res.push_back(matrix[x][y]);
			st[x][y] = true;
			int a = x + dx[d], b = y + dy[d];
			if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
				d = (d + 1) % 4;
				a = x + dx[d], b = y + dy[d];
			}
			x = a, y = b;
		}
		return res;
	}

	bool isPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() && popV.empty()) return true;
		if (pushV.empty() || popV.empty() || pushV.size() != popV.size()) return false;
		stack<int> s;
		int popId = 0;


		for (int pushId = 0; pushId < pushV.size(); ++pushId) {
			s.push(pushV[pushId]);
			while (!s.empty() && s.top() == popV[popId]) {
				s.pop();
				++popId;
			}
		}

		if (s.empty()) return true;
		return false;
	}

	vector<int> printFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			res.push_back(t->val);
			if (t->left) q.push(t->left);
			if (t->right)q.push(t->right);
		}
		return res;
	}

	vector<vector<int>> printFromTopToBottomLine(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;

		queue<TreeNode*> q;
		q.push(root);
		q.push(nullptr);
		
		vector<int> level;
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			if (!t) {
				if (level.empty()) break;
				res.push_back(level);
				level.clear();
				q.push(nullptr);
				continue;
			}
			level.push_back(t->val);
			if (t->left)q.push(t->left);
			if (t->right)q.push(t->right);
		}
		return res;
	}

	vector<vector<int>> printFromTopToBottomZ(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;

		queue<TreeNode*> q;
		q.push(root);
		q.push(nullptr);
		bool flag = false;

		vector<int> level;
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			if (!t) {
				if (level.empty()) break;
				if (flag) reverse(level.begin(), level.end());
				flag = !flag;
				res.push_back(level);
				level.clear();
				q.push(nullptr);
				continue;
			}
			level.push_back(t->val);
			if (t->left)q.push(t->left);
			if (t->right)q.push(t->right);
		}
		return res;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		if (nums.size() == 0) return res;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					res.push_back(i);
					res.push_back(j);
				}
			}
		}
		return res;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		
		vector<vector<int>> res;
		for (int i = 0; i < nums.size(); i++) {
			if ((i > 0) && (i < nums.size()) && (nums[i] == nums[i - 1]))
				continue;
			int l = i + 1, r = nums.size() - 1;
			while (l < r) {
				int s = nums[i] + nums[l] + nums[r];
				if (s > 0) r--;
				else if (s < 0) l++;
				else {
					res.push_back(vector<int> {nums[i], nums[l], nums[r]});
					while (l < r && nums[l] == nums[l + 1]) l++;
					while (l < r && nums[r] == nums[r - 1]) r--;
					l++; r--;
				}
			}
		}
		return res;
	}

	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)return 0;
		int k = 0, i = 1;
		for (i; i < n; i++)
		{
			if (nums[k] != nums[i]) nums[++k] = nums[i];
		}
		return k + 1;
	}

	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		if (n == 0)return 0;
		int k = -1, i = 0;
		for (i; i < n; i++)
		{
			if (nums[i] != val) nums[++k] = nums[i];
		}
		return k + 1;
	}

	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return;
		bool flag = false;
		for (int i = n - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1]) {
				swap(nums[i], nums[i - 1]);
				flag = true;
				break;
			}
		}
		if (!flag)reverse(nums.begin(), nums.end());
	}

	void solve(int i, vector<int>& candidates, int sum,vector<int>& ch, int target, vector<vector<int>>& ans) {
		// 注意这里的 ch 是引用。
		if (sum == target) { // 找到目标值，添加答案。
			ans.push_back(ch);
			return;
		}
		if (i == candidates.size() || sum > target) // 超出范围回溯。
			return;

		solve(i + 1, candidates, sum, ch, target, ans);

		ch.push_back(candidates[i]);
		solve(i, candidates, sum + candidates[i], ch, target, ans);
		ch.pop_back();
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		sort(candidates.begin(), candidates.end());
		vector<int> ch; // ch 记录已选择的数字。
		solve(0, candidates, 0, ch, target, ans);
		return ans;
	}

	vector<int> plusOne(vector<int>& digits) {
		int t = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			digits[i] += t;
			t = digits[i] / 10;
			digits[i] %= 10;
		}
		if (t)
		{
			digits.push_back(0);
			for (int i = digits.size() - 2; i >= 0; i--)
				digits[i + 1] = digits[i];
			digits[0] = 1;
		}
		return digits;
	}

};

class MinStack {
public:
	stack<int> stkValue;
	stack<int> stkMin;
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stkValue.push(x);
		if (stkMin.empty() || stkMin.top() >= x)stkMin.push(x);
	}

	void pop() {
		if (stkValue.top() == stkMin.top())stkMin.pop();
		stkValue.pop();
	}

	int top() {
		return stkValue.top();
	}

	int getMin() {
		return stkMin.top();
	}
};

int main()
{
	vector<int> pushV({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
	int c = 13 / 10;
	vector<int> popV({ 2, 3, 1, 4, 7, 6, 5, 8, 11, 10, 9, 15, 14, 13, 12 });

	Solution test;
	test.isPopOrder(pushV, popV);
	vector<vector<bool>> st(5, vector<bool>(5, false));
}