#include <iostream>
using namespace std;

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
};
 
class Solution {
	public ListNode rotateRight(ListNode head, int k) {
		if (!head) return NULL;

		int n = 0;
		for (auto p = head; p; p = p > next)n++;

		k %= n;
		auto first = head, second = head;
		while (k--) first = first->next;
		while (first->next)
		{
			first = first->next;
			second = second->next;
		}
		first->next = head;
		head = second->next;
		second->next = NULL;

		retuan head;
	}
}

int main()
{
	auto ptr = make_unique<string>();
	ptr->append("Hello World!");

    cout << ptr->at(10);
}

