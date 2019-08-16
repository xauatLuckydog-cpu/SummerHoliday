// DayTwentyFour.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
struct ListNode {
	int val;
	ListNode* next, * random;
	ListNode(int x) : val(x), next(NULL), random(NULL){}
};

class Solution {
public:
	string toGoatLatin(string S) {
		int index = 1;
		string add = "ma", res, temp;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == 'a' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' || S[i] == 'e' || S[i] == 'A' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U' || S[i] == 'E')
			{

				while (S[i] != ' ') {
					temp += S[i];
					i++;
					if (i >= S.size())break;
				}
				temp += add;
				for (int j = 0; j < index; j++)temp += 'a';
				index++;
				res += temp + ' ';
				temp = "";
				continue;
			}
			else {
				char c = S[i];
				i++;

				while (S[i] != ' ') {
					temp += S[i];
					i++;
					if (i >= S.size())break;
				}
				temp += c + add;
				for (int j = 0; j < index; j++)temp += 'a';
				index++;
				res += temp + ' ';
				temp = "";
				continue;
			}
		}

		res = res.substr(0, res.size() - 1);
		return res;
	}
	int lengthOfLastWord(string s) {
		int sum = 0, res = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == ' ')
			{
				if (sum) res = sum;
				sum = 0;
			}
			else
				sum++;
		if (sum) res = sum;
		return res;
	}
	int strStr(string haystack, string needle) {
		int n = haystack.length(), m = needle.length();
		for (int i = 0; i < n - m + 1; i++) {
			bool ok = true;
			for (int j = 0; j < m; j++)
				if (haystack[i + j] != needle[j]) {
					ok = false;
					break;
				}
			if (ok)
				return i;
		}
		return -1;
	}
	vector<string> ress;
	void dfss(int l, int r, int n, string cur) {
		if (l == n && r == n) {
			ress.push_back(cur);
			return;
		}
		if (l < n)
			dfss(l + 1, r, n, cur + "(");

		if (r < l)
			dfss(l, r + 1, n, cur + ")");
	}
	vector<string> generateParenthesis(int n) {
		if (n == 0)
			return ress;
		dfss(0, 0, n, "");
		return ress;
	}
	bool isValid(string s) {
		stack<char> stk;
		if (s.length() == 0)return true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')stk.push(s[i]);
			if (s[i] == ')') {

				if (stk.top() != '(' || stk.empty())return false;
				stk.pop();
				continue;
			}
			if (s[i] == ']') {
				if (stk.top() != '[' || stk.empty())return false;
				stk.pop();
				continue;
			}
			if (s[i] == '}') {
				if (stk.top() != '{' || stk.empty())return false;
				stk.pop();
				continue;
			}
		}
		if (!stk.empty())return false;
		return true;
	}
	string addBinary(string a, string b) {
		if (a.size() < b.size()) swap(a, b);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int t = 0;
		string res;
		int k = 0;
		while (k < b.size())
		{
			t += a[k] - '0' + b[k] - '0';
			res += to_string(t & 1);
			t /= 2;
			k++;
		}
		while (k < a.size()) //处理a超出b的部分
		{
			t += a[k] - '0';
			res += to_string(t & 1);
			t /= 2;
			k++;
		}
		if (t) res += '1';
		reverse(res.begin(), res.end());
		return res;
	}
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		string s = strs[0];
		int size = s.size();
		for (int i = 1; i < strs.size(); i++) {
			for (int j = 0; j < size; j++) {
				if (s[j] != strs[i][j]) {
					size = j;
					break;
				}
			}
		}
		return s.substr(0, size);
	}
	string defangIPaddr(string address) {
		int i = 0;
		vector<char> temp;
		string res;
		while (i < address.size())
		{
			if (address[i] == '.')
			{
				temp.push_back('[');
				temp.push_back('.');
				temp.push_back(']');
				i++;
				continue;
			}
			temp.push_back(address[i]);
			i++;
		}
		for (auto x : temp) {
			res += x;
		}
		return res;
	}
	int numberOf1Between1AndN_Solution(int n) {

	}
	int maxSubArray(vector<int>& nums) {
		int res = INT_MIN, s = 0;
		for (auto x : nums) {
			if (s < 0) s = 0;
			s += x;
			res = max(res, s);
		}
		return res;
	}
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>>min_heap;
	void insert(int num) {
		max_heap.push(num);
		if (min_heap.size() && max_heap.top() > min_heap.top()) {
			auto maxv = max_heap.top(), minv = min_heap.top();
			max_heap.pop(), min_heap.pop();
			max_heap.push(minv), min_heap.push(maxv);
		}
		if (max_heap.size() > min_heap.size() + 1)
		{
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
	}
	double getMedian() {
		if (max_heap.size() + min_heap.size() & 1) return	max_heap.top();
		return (max_heap.top() + min_heap.top()) / 2.0;
	}
	int moreThanHalfNum_Solution(vector<int>& nums) {
		int cnt = 0, val = -1;
		for (auto x : nums) {
			if (!cnt) val = x, cnt = 1;
			else {
				if (x == val)cnt++;
				else cnt--;
			}
		}
		return val;
	}
	vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
		sort(input.begin(), input.end());
		vector<int> res;
		for (int i = 0; i < k; i++)
		{
			res.push_back(input[i]);
		}
		return res;
	}
	vector<int> getLeastNumbers_Solution2(vector<int> input, int k) {
		priority_queue<int> heap;
		for (auto x : input) {
			heap.push(x);
			if (heap.size() > k) heap.pop();
		}

		vector<int> res;
		while (heap.size())res.push_back(heap.top()), heap.pop();
		reverse(res.begin(), res.end());
		return res;
	}
	vector<vector<int>> ans;
	vector<int> path;
	vector<vector<int>> permutation(vector<int>& nums) {
		path.resize(nums.size());
		sort(nums.begin(), nums.end());
		dfs_num(nums, 0, 0, 0);
		return ans;
	}
	void dfs_num(vector<int>& nums, int u, int start, int state) {
		if (u == nums.size()) {
			ans.push_back(path);
			return;
		}
		if (!u || nums[u] != nums[u - 1]) start = 0;
		for (int i = start; i < nums.size(); i++) {
			if (!(state >> i & 1))
			{
				path[i] = nums[u];
				dfs_num(nums, u + 1, i + 1, state + (1 << i));
			}
		}
	}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		dfs_s(root, res);
		return res;
	}
	void dfs_s(TreeNode* root, string& res)
	{
		if (!root)
		{
			res += "null ";
			return;
		}
		res += to_string(root->val) + ' ';
		dfs_s(root->left, res);
		dfs_s(root->right, res);
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int u = 0;
		return dfs_d(data, u);
	}
	TreeNode* dfs_d(string data, int& u) {
		if (u == data.size()) return NULL;
		int k = u;
		while (data[k] != ' ')k++;
		if (data[u] == 'n') {
			u = k + 1;
			return NULL;
		}
		int val = 0;
		for (int i = u; i < k; i++)val = val * 10 + data[i] - '0';
		u = k + 1;
		auto root = new TreeNode(val);
		root->left = dfs_d(data, u);
		root->right = dfs_d(data, u);
		return root;
	}
	ListNode* copyRandomList(ListNode* head) {
		for (auto p = head; p;) {
			auto np = new ListNode(p->val);
			auto next = p->next;
			p->next = np;
			np->next = next;
			p = next;
		}
		for (auto p = head; p; p = p->next->next) {
			if (p->random)
				p->next->random = p->random->next;
		}
		auto dummy = new ListNode(-1);
		auto cur = dummy;
		for (auto p = head; p; p = p->next) {
			cur->next = p->next;
			cur = cur->next;
			p = p->next;
		}
		return dummy->next;
	}
	TreeNode* convert(TreeNode* root) {
		if (!root) return NULL;
		auto sides = dfsSides(root);
		return sides.first;
	}
	pair<TreeNode*, TreeNode*>dfsSides(TreeNode* root) {
		if (!root->left && !root->right) return{ root,root };
		if (root->left && root->right) {
			auto lsides = dfsSides(root->left), rsides = dfsSides(root->right);
			lsides.second->right = root, root->left = lsides.second;
			root->right = rsides.first, rsides.first->left = root;
			return { lsides.first,rsides.second };
		}
		if (root->left)
		{
			auto lsides = dfsSides(root->left);
			lsides.second->right = root, root->left = lsides.second;
			return { lsides.first,root };
		}
		if (root->right)
		{
			auto rsides = dfsSides(root->right);
			root->right = rsides.first, rsides.first->left = root;
			return { root,rsides.second };
		}
	}
	vector<vector<int>> res;
	//vector<int> path;
	vector<vector<int>> findPath(TreeNode* root, int sum) {
		dfs(root, sum);
		return res;
	}
	void dfs(TreeNode* root, int sum) {
		if (!root) return;
		path.push_back(root->val);
		sum -= root->val;
		if (!root->left && !root->right && !sum) res.push_back(path);
		dfs(root->left, sum);
		dfs(root->right, sum);
		path.pop_back();
	}
};


int main()
{
	Solution test;
	string res = test.toGoatLatin("I speak Goat Latin");
	cout << "I speak Goat Latin" << endl << res;
}