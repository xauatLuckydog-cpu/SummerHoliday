// DayTwentyThree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
	for (int i = 1; i < vec.size(); i++) {
		p = new ListNode(vec[i]);
		pre->next = p;
		pre = p;
	}
	return head;
}

vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> ret;
		ListNode* cur = root;
		int count = 0;
		while (cur) {
			count++;
			cur = cur->next;
		}
		cur = root;
		int size = count / k;
		int rem = count % k;
		for (int i = 0; i < k; ++i) {
			if (cur) {
				ListNode* Head = new ListNode(-1);
				ListNode* prev = Head;

				for (int j = 0; j < size + (rem > 0 ? 1 : 0); ++j) {
					prev->next = new ListNode(cur->val);
					prev = prev->next;
					cur = cur->next;
				}
				rem--;
				ret.push_back(Head->next);
			}
			else {
				ret.push_back(NULL);
			}
		}
		return ret;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	vector<int> vec1, vec2;
	vector<int> res;
	int c = 0;
	ListNode* head = NULL;
	while (l1)vec1.push_back(l1->val), l1 = l1->next;
	while (l2)vec2.push_back(l2->val), l2 = l2->next;
	while (!vec1.empty() && !vec2.empty()) {
		c += vec1.back() + vec2.back();
		res.push_back(c % 10);
		c /= 10;
		vec1.pop_back();
		vec2.pop_back();
	}
	while (!vec1.empty()) {
		c += vec1.back();
		res.push_back(c % 10);
		c /= 10;
		vec1.pop_back();
	}
	while (!vec2.empty()) {
		c += vec2.back();
		res.push_back(c % 10);
		c /= 10;
		vec2.pop_back();
	}

	if (c) res.push_back(c);
	head = creat(vector<int>(res.rbegin(), res.rend()));
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

bool isPalindrome(string s) {
	if (s.empty()) return true;
	for (int i = 0; i < s.length();) {
		if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i]<'0' || s[i]>'9'))
		{
			s.erase(i, 1);
			continue;
		}
		i++;
	}
	if (s.length() == 1)return false;
	int i = 0, j = s.length() - 1;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}

	while (i <= j)
	{
		if (s[i] != s[j])return false;
		if (i > j)return true;

		i++;
		j--;
	}
	return true;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int> res;
	int i = 0, j = 0;
	for (i,j; i < m && j < n;)
	{
		if (nums1[i] > nums2[j]) res.push_back(nums2[j++]);
		res.push_back(nums1[i++]);
	}
	while (i < m)res.push_back(nums1[i++]);
	while (j < n)res.push_back(nums2[j++]);
	nums1 = res;
}

void moveZeroes(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n;)
	{
		if (nums[i] == 0)
		{
			nums.erase(nums.begin() + i);
			nums.push_back(0);
			n--;
			continue;
		}
		i++;
	}
}

void reverseString(vector<char>& s) {
	reverse(s.rbegin(), s.rend());
}

string reverseVowels(string s) {
	int i = 0, j = s.length() - 1;
	if (s.empty())return s;
	while (i < j)
	{
		if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') && (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') || (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') && (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')) {
			swap(s[i], s[j]);
			i++;
			j--;
		}
		if ((s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')){
			i++;
		}
		if ((s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U')) {
			j--;
		}
	}
	return s;
}

int main()
{
	reverseVowels("aA");
}
