// DayTwentyThree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x),next (NULL) {};
};

ListNode* creat(vector<int> vec) {//利用传入的vector建立一个新的链表。
	ListNode* p, * pre, * head;
	head = new ListNode(vec[0]);
	pre = head;
	for (int i = 1; i < 5; i++) {
		p = new ListNode(vec[i]);
		pre->next = p;
		pre = p;
	}
	return head;
}

bool search(ListNode* head, int target)
{
	ListNode* dummy = head;
	while (dummy != NULL) {
		if (dummy->val == target)return true;
		dummy = dummy->next;
	}
	return false;
}

bool deleteNode(ListNode* head, int target) {//删除第一个val等于target的结点
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	while (dummy != NULL) {
		if (dummy->next->val == target)
		{
			dummy->next = dummy->next->next;
			return true;
		}
		dummy = dummy->next;
	}
	return false;
}

bool insertNode(ListNode* head, int target) {//插入到第一个val大于target的结点之前
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	while (dummy != NULL) {
		if (dummy->next->val >= target) {
			ListNode* temp = new ListNode(target);
			
			temp->next = dummy->next;
			dummy->next = temp;
			return true;
		}
		dummy = dummy->next;
	}
	return false;
}

int main()
{
	vector<int> vec = { 1,2,3,4,5 };
	auto p = creat(vec);
	auto flag22 = insertNode(p, 0);
	
	//char arrays[] = "China";
	//int n = sizeof(arrays);
	//char s1[10], s2[10] = { "books" };
	//strcpy_s(s1, s2);
	//int a[3][4][2];
	//double* array[8];
	vector<int> array;
	array.push_back(100);

	array.push_back(300);

	array.push_back(300);

	array.push_back(500);
	vector<int>::iterator itor;
	for (itor=array.begin();itor!=array.end(); itor++)
	{
		if (*itor == 300) {
			itor = array.erase(itor);
		}
	}
	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << " ";
	}

	int flag = 0;
	bool test = 0;

	if (!array.empty())cout << "yes";
	else cout << "no";

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
