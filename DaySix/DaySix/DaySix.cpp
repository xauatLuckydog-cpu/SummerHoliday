// DaySix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* findKthToTail(ListNode* head, int k) {
		auto first = head, second = head;
		while (k--) first = first->next;
		while (first->next) {
			first = first->next;
			second = second->next;
		}
		return second;
	}
};

int main()
{
	/*vector < vector<bool>> st(10, vector<bool>(20));
	queue<pair<int, int>> q;
	q.push({ 0,0 });*/
	int t = -1;
	unsigned int n = t;
	int s = 0;
	while (n) s += n & 1, n >>= 1;
    std::cout << "Hello World!\n"; 
}


