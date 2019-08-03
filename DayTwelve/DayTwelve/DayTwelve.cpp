// DayTwelve.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long LL;
const int N = 300010;
int n, m;
int q[N];
LL s[N];



//typedef pair<int, int> PII;
//const int N = 200010;
//
//int n;
//PII a[N];
//
//void quicksort(int q[], int l, int r) {
//	if (l > r)return;
//
//	int i = l - 1, j = r + 1, x = q[l + r >> 1];
//	while (i < j)
//	{
//		do i++; while (q[i] < x);
//		do j--; while (q[j] > x);
//		if (i < j)swap(q[i], q[j]);
//	}
//	quicksort(q, l, j), quicksort(q, j + 1, r);
//}
//
//void mergesort(int q[], int l, int r)
//{
//	int tmp[1000010] = { 0 };
//	if (l >= r)return;
//
//	int mid = l + r >> 1;
//	mergesort(q, l, mid);
//	mergesort(q, mid + 1, r);
//	int k = 0, i = l, j = mid + 1;
//	while (i <= mid && j <= r)
//	{
//		if (q[i] < q[j])tmp[k++] = q[i++];
//		else tmp[k++] = q[j++];
//	}
//	while (i <= mid)tmp[k++] = q[i++];
//	while (j <= r)tmp[k++] = q[j++];
//
//	for (i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];
//}
//
//bool check(int x)
//{
//	//TUDO
//}
//
//int bsearch_1(int l, int r)
//{
//	while (l < r)
//	{
//		int mid = l + r >> 1;
//		if (check(mid))r = mid;
//		else l = mid + 1;
//	}
//	return l;
//}
//
//int bsearch_2(int l, int r)
//{
//	while (l < r)
//	{
//		int mid = l + r + 1 >> 1;
//		if (check(mid))l = mid;
//		else r = mid - 1;
//	}
//	return l;
//}
//
//bool check(double x)
//{
//	//TUDO
//}
//
//double bsearch_3(double l, double r)
//{
//	const double eps = 1e-6;
//	while (r-l>eps)
//	{
//		double mid = (l + r) / 2;
//		if (check(mid))r = mid;
//		else l = mid + 1;
//	}
//	return l;
//}

int main()
{

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}
	int hh = 0, tt = 0;

	LL res = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		if (i - q[hh] > m)hh++;
		res = max(res, s[i] - s[q[hh]]);
		while (hh <= tt && s[q[tt]] >= s[i])tt--;
		q[++tt] = i;
	}
	cout << res << endl;

	return 0;

	/*cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n);

	int res = 1, last = INT_MAX, dir = -1;
	for (int i = 0; i < n;)
	{
		int j = i;
		while (j < n && a[j].first == a[i].first)j++;

		int minp = a[i].second, maxp = a[j - 1].second;
		if (dir == -1)
		{
			if (last > maxp)last = minp;
			else dir = 1, last = maxp;
		}
		else {
			if (last < minp)last = maxp;
			else
			{
				res++;
				dir = -1;
				last = minp;
			}

		}
		i = j;
	}
	cout << res;
	return 0;*/
}


