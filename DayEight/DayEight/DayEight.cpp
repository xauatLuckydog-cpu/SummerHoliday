// DayEight.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;




 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		stack<TreeNode*> stk;
		TreeNode* p = root;
		int ans = 0;
		if (root != NULL)stk.push(root);
		while (!stk.empty())
		{
			TreeNode* top = stk.top();
			if (top->val >= L || top->val <= R) {
				ans += top->val;
			}
			if (top->left != NULL)stk.push(top->left);
			if (top->right != NULL)stk.push(top->right);
		}

		while (p != NULL || !stk.empty())
		{
			while (p != NULL)
			{
				stk.push(p);
				p = p->left;
			}
			if (!stk.empty())
			{
				p = stk.top();
				if (p->val >= L || p->val <= R) {
					ans += p->val;
				}
				stk.pop();
				p = p->right;
			}
		}
		return ans;
	}
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1 && !t2)
			return NULL;
		if (!t1 && t2)
			return t2;
		if (t1 && !t2)
			return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
	int hammingDistance(int x, int y) {
		int ans = 0;
		while (x)
		{
			if (((x & 0x01) != (y & 0x01))) {
				ans++;
			}
			x = x >> 1;
			y = y >> 1;
		}
		return ans;
	}
	bool judgeCircle(string moves) {
		int bot[1][2] = { 0,0 };
		int n = moves.length();
		for (int i = 0; i < n; i++)
		{
			if (moves[i] == 'U')
			{
				bot[0][1] += 1;
			}
			if (moves[i] == 'D')
			{
				bot[0][1] -= 1;
			}
			if (moves[i] == 'L')
			{
				bot[0][0] -= 1;
			}
			if (moves[i] == 'R')
			{
				bot[0][0] += 1;
			}
		}
		return bot[0][1] && bot[0][0];
	}

	};

int main()
{
	Solution test;
	string s = "LL";
	int nnn = 30;
	bool flag = nnn % 4;

	vector<int> sorted;
	for (int i = 0; i < 10; i++)
	{
		sorted.push_back(i * rand());
	}

	sort(sorted.begin(), sorted.end());

	test.judgeCircle(s);
	int n = 0&&0;
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
