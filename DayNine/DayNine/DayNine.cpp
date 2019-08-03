// DayNine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = (l1 != NULL ? l1 : l2);
		return dummy->next;
	}
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = head;
		ListNode* temp = NULL;
		while (dummy->next != NULL)
		{
			if (dummy->val == dummy->next->val)
			{
				temp = dummy;
				for (; temp->next != NULL && temp->val == temp->next->val; temp = temp->next);
				dummy->next = temp;
			}
			dummy = dummy->next;
		}
		return dummy;
	}

	ListNode* Create()
	{
		ListNode* p = NULL, * s,* head = NULL;
		int x = 0, cycle = 1;
		while (cin >> x)
		{
			s = new ListNode(x);
			if (NULL == head)
			{
				head = s;
			}
			else
			{
				p->next = s;
			}
			p = s;
		}
		p->next = NULL;
		if (NULL != head)
			cout << "创建成功！" << endl;
		else
			cout << "没有数据输入！" << endl;
		return head;
	}
};


int main()
{
	int a[5] = { 1,2,3,4,5 };
	memset(a, 1, sizeof(a));
	for (size_t i = 0; i < 5; i++)
	{
		cout << a[i];
	}

}