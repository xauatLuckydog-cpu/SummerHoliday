//// DayTwentyNine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//ListNode* creat(vector<int> vec) {//利用传入的vector建立一个新的链表。
//	ListNode* p, * pre, * head;
//	head = new ListNode(vec[0]);
//	pre = head;
//	for (int i = 1; i < vec.size(); i++) {
//		p = new ListNode(vec[i]);
//		pre->next = p;
//		pre = p;
//	}
//	return head;
//}
//
//ListNode* reverseList(ListNode* head)
//{
//	ListNode* pre = nullptr;
//	auto cur = head;
//	while (cur)
//	{
//		auto next = cur->next;
//		cur->next = pre;
//		pre = cur;
//		cur = next;
//	}
//	return pre;
//}
//
//
//int main()
//{
//	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
//	auto p = creat(vec);
//	auto orderp = reverseList(p);
//	return 0;
//}
//
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//const int N = 210;
//int input[N][N];
//
//int main() {
//	int n;
//	cin >> n;
//	int res[N][N] = { 0 };
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> input[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		bool flag = false;
//		for (int j = 0; j < n; j++) {
//			if (input[i][j] > 3) {
//				res[i][j]++;
//				flag = true;
//			}
//		}
//		if (!flag)ans++;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i + 1; j++) {
//			if (res[i][j] > 0) {
//				if (res[i+1][j + 1] > 0)continue;
//				ans++;
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int input[4][4];
//int n;
//
//void moveUp() {
//	bool flag;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (!input[i][j])continue;
//			if (input[i][0] == 0 && input[i][0] == input[i][j]) {
//				input[i][0] *= 2;
//				input[i][j] = 0;
//				continue;
//			}
//			if (input[i][1] == 0 && input[i][1] == input[i][j]) {
//				input[i][1] *= 2;
//				input[i][j] = 0;
//				continue;
//			}
//			if (input[i][2] == 0 && input[i][2] == input[i][j]) {
//				input[i][2] *= 2;
//				input[i][j] = 0;
//				continue;
//			}
//		}
//	}
//}
//void moveDown() {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 3; j >= 0; j--) {
//			input[i][4] += input[i][j];
//		}
//	}
//}
//void moveLeft() {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 1; j < 4; j++) {
//			input[0][i] += input[j][i];
//		}
//	}
//}
//void moveRight() {
//
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < 4; i++) 
//		for (int j = 0; j < 4; j++) 
//			cin >> input[i][j];
//	switch (n)
//	{
//	case 1:moveUp();
//		break;
//	case 2:moveDown();
//		break;
//	case 3:moveLeft();
//		break;
//	case 4:moveRight();
//		break;
//	default:
//		break;
//	}
//}
//
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 20010;
int input[N];
bool bl[N];

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
int main() {
	int n;
	cin >> n;
	unordered_map<int, int> umap;
	for (int i = 0; i < n; i++)cin >> input[i];
	for (int i = 0; i < n; i++) {
		memset(bl, false, sizeof(bl));
		for (int j = i + 1; j < n; j++) {
			if (gcd(input[i], input[j]) == 1)continue;
			if (!bl[gcd(input[i], input[j])]) {
				umap[gcd(input[i], input[j])]++;
				bl[gcd(input[i], input[j])] = true;
			}
			
		}
	}
	int ans = 0;
	for (auto x : umap)ans = max(ans, x.second);
	cout << ans + 1;
	return 0;
}