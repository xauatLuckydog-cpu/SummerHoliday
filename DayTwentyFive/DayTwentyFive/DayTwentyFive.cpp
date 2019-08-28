// DayTwentyFive.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	// f[0] = nums[0] f[i]  f[i] = max(nums[i],f[i-1]+nums[i]) ans = max(ans,f[i])
	int maxSubArray(vector<int>& nums) {
		int n = nums.size(), ans;
		vector<int> f(n);
		f[0] = nums[0];
		ans = f[0];
		for (int i = 1; i < n; i++) {
			f[i] = max(f[i - 1] + nums[i], nums[i]);
			ans = max(ans, f[i]);
		}
		return ans;
	}
	string decodeString(string s) {
		string res;
		for (int i = 0; i < s.size();)
		{
			if (!isdigit(s[i])) res += s[i++];
			else
			{
				int j = i;
				while (isdigit(s[j])) j++;
				int t = atoi(s.substr(i, j - i).c_str());
				int k = j + 1, sum = 0;
				while (sum >= 0)
				{
					if (s[k] == '[') sum++;
					if (s[k] == ']') sum--;
					k++;
				}
				string str = decodeString(s.substr(j + 1, k - j - 2));
				while (t--) res += str;
				i = k;
			}
		}
		return res;
	}
	int evalRPN(vector<string>& tokens) {
		stack<int> sta;
		for (auto& t : tokens)
			if (t == "+" || t == "-" || t == "*" || t == "/")
			{
				int a = sta.top();
				sta.pop();
				int b = sta.top();
				sta.pop();
				if (t == "+") sta.push(a + b);
				else if (t == "-") sta.push(b - a);
				else if (t == "*") sta.push(a * b);
				else sta.push(b / a);
			}
			else sta.push(atoi(t.c_str()));
		return sta.top();
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		while (root)
		{
			if (!root->left)
			{
				res.push_back(root->val);
				root = root->right;
			}
			else
			{
				TreeNode* pre = root->left;
				while (pre->right && pre->right != root) pre = pre->right;
				if (pre->right) pre->right = 0, root = root->right;
				else
				{
					pre->right = root;
					res.push_back(root->val);
					root = root->left;
				}
			}
		}
		return res;
	}
	unordered_map<char, int> count;
	queue<char> q;
	//Insert one char from stringstream
	void insert(char ch) {
		if (++count[ch] > 1)
		{
			while (q.size() && count[q.front()] > 1) q.pop();
		}
		else q.push(ch);
	}
	//return the first appearence once char in current stringstream
	char firstAppearingOnce() {
		if (q.empty())return '#';
		return q.front();
	}
	char firstNotRepeatingChar(string s) {
		unordered_map<char, int> count;
		for (auto c : s)count[c]++;
		char res = '#';
		for (auto c : s) {
			if (count[c] == 1) {
				res = c;
				break;
			}
		}
		return res;
	}
	int getUglyNumber(int n) {
		vector<int> q(1, 1);
		int i = 0, j = 0, k = 0;
		while (--n) {
			int t = min(q[i] * 2, min(q[j] * 3, q[k] * 5));
			q.push_back(t);
			if (q[i] * 2 == t)i++;
			if (q[j] * 3 == t)j++;
			if (q[k] * 5 == t)k++;
		}
		return q.back();
	}
	int longestSubstringWithoutDuplication(string s) {
		unordered_map<char, int> count;
		int res = 0;
		for (int i = 0, j = 0; j < s.size(); j++) {
			if (++count[s[j]] > 1) {
				while (count[s[i]] == 1)count[s[i++]] --;
				count[s[i++]] --;
			}
			res = max(res, j - i + 1);
		}
		return res;
	}
	int getMaxValue(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> f(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
			}
		}
		return f[n][m];
	}
	int getTranslationCount(string s) {
		int n = s.size();
		vector<int> f(n + 1);
		f[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			f[i] = f[i - 1];
			int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
			if (t >= 10 && t <= 25)f[i] += f[i - 2];
		}
		return f[n];
	}
	static bool cmp(int a, int b) {
		auto as = to_string(a), bs = to_string(b);
		return as + bs < bs + as;
	}
	string printMinNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		string res;
		for (int i = 0; i < nums.size(); i++) {
			res += to_string(nums[i]);
		}
		return res;

	}
	int digitAtIndex(int n) {
		long long i = 1, s = 9, base = 1;
		while (n > i * s) {
			n -= i * s;
			i++;
			s *= 10;
			base *= 10;
		}
		int number = base + (n + i - 1) / i - 1;
		int r = n % i ? n % i : i;
		for (int j = 0; j < i - r; j++)number /= 10;
		return number % 10;
	}
};

class MyStack {
public:
	deque<int> q;
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push_back(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		q.pop_back();
		return q.back();
	}

	/** Get the top element. */
	int top() {
		return q.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};

class MyQueue {
public:
	deque<int> q;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		q.push_back(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int x = q.back();
		q.pop_back();
		return x;
	}

	/** Get the front element. */
	int peek() {
		return q.front();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return q.empty();
	}
};

int main()
{
	//Solution test;
	//string s = "asdasd[asdasd[[asd[a[sd[asd";
	//vector<vector<char>> input;
	//int n, m, x, y;
	//char c;
	//cin >> n >> m >> x >> y;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cin >> c;
	//		input[i].push_back(c);
	//	}
	//}
	//for (int i = 0; i < n; i++) {
	//	if()
	//}
	vector<vector<char>> input;
	int n, m, x, y;
	string s;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> s;
			for (auto c : s) {
				input[i].push_back(c);
			}
			
		}
	}

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
