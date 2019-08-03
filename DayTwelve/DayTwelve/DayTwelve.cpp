// DayTwelve.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


void quicksort(int q[], int l, int r) {
	if (l > r)return;

	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j)swap(q[i], q[j]);
	}
	quicksort(q, l, j), quicksort(q, j + 1, r);
}

void mergesort(int q[], int l, int r)
{
	int tmp[1000010];
	if (l >= r)return;

	int mid = l + r >> 1;
	mergesort(q, l, mid);
	mergesort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (q[i] < q[j])tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while (i <= mid)tmp[k++] = q[i++];
	while (j <= r)tmp[k++] = q[j++];

	for (i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];
}

bool check(int x)
{
	//TUDO
}

int bsearch_1(int l, int r)
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	return l;
}

int bsearch_2(int l, int r)
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid))l = mid;
		else r = mid - 1;
	}
	return l;
}

bool check(double x)
{
	//TUDO
}

double bsearch_3(double l, double r)
{
	const double eps = 1e-6;
	while (r-l>eps)
	{
		double mid = (l + r) / 2;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	return l;
}

int main()
{
    std::cout << "Hello World!\n"; 
}


