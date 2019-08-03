// DayFive.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N],temp[N];

// struct ListNode {
//     int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//  };
//
//class Solution {
//public:
//	ListNode* sortList(ListNode* head) {
//
//		int n = 0;
//		for (auto p = head; p; p = p->next) n++;
//
//		auto dummy = new ListNode(-1);
//		dummy->next = head;
//
//		for (int i = 1; i < n; i *= 2)
//		{
//			auto cur = dummy;
//			for (int j = 0; j + i < n; j += i * 2)//自下而上的归并，第一次排两个，第二次四个，第三次八个以此类推。
//			{
//				auto left = cur->next, right = cur->next;
//				for (int k = 0; k < i; k++) right = right->next;
//				int l = 0, r = 0;
//				while (l < i && r < i && right)
//					if (left->val <= right->val)
//					{
//						cur->next = left;
//						cur = left;
//						left = left->next;
//						l++;
//					}
//					else
//					{
//						cur->next = right;
//						cur = right;
//						right = right->next;
//						r++;
//					}
//				while (l < i)
//				{
//					cur->next = left;
//					cur = left;
//					left = left->next;
//					l++;
//				}
//				while (r < i && right)
//				{
//					cur->next = right;
//					cur = right;
//					right = right->next;
//					r++;
//				}
//				cur->next = right;
//			}
//		}
//
//		return dummy->next;
//	}
//};

void quick_sort(int q[], int l, int r)
{
	if (l >= r)return;
	int x = q[l], i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j)swap(q[i], q[j]);
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

void merge_sort(int q[], int l, int r)
{
	if (l >= r)return;//如果数组中元素小于1，返回
	
	int mid = l + r >> 1;//除二寻找中位
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

	int k = 0, i = 1, j = mid + 1;
	while (i <= mid && j <= r)
		if (q[i] <= q[j])temp[k++] = q[i++];
		else temp[k++] = q[j++];
	while (i <= mid)temp[k++] = q[i++];
	while (j <= r)temp[k++] = q[j++];
	for (i = l, j = 0; i <= r; i++, j++) {
		q[i] = temp[j];
	}
}

bool check(int mid)
{
	//TODO 在这里完成二分查找的中点判别，具体根据题目来设计
}

int bSearch1(int l, int r)
{
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	return l;
}

int bSearch2(int l, int r)
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid))l = mid;
		else r = mid - 1;
	}
	return l;
}

double fSearch(double x)
{
	double l = 0, r = x;
	//for(int i = 0; i < 100; i++)//不考虑精度，直接迭代100次
	while (r - l > 1e-8) {//这里的精度主要看题目要求保留的精度，一般精度大2 .
		double mid = (l + r) / 2;
		if (mid * mid >= x)r = mid;//mid*mid>=x即为mid >= sqrt(x) 
		else l = mid;
	}
	return l;
}

int main()
{
	scanf_s("%d", &n);
	for (size_t i = 0; i < n; i++)scanf_s("%d", &q[i]);
	quick_sort(q, 0, n - 1);
	for (size_t i = 0; i < n; i++)printf_s("%d", q[i]);
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
