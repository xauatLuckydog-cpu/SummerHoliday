// DayThirteen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include  <algorithm>
#include <stack>
using namespace std;


//typedef long long LL;
//const int maxn = 100010;
//const int mod = 1000000007;
//int n, ans[4], hashtable[4] = { false };

//
//void pailie(int index)
//{
//	if (index > n)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			cout << ans[i] << " ";
//		}
//		cout << endl;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (!hashtable[i])
//		{
//			ans[index] = i;
//			hashtable[i] = true;
//			pailie(index + 1);
//			hashtable[i] = false;
//		}
//	}
//}
//
//void SelectSort(int p[], int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		int k = i;
//		for (int j = i; j < length; j++) {
//			if (p[j] < p[k])
//				k = j;
//		}
//		swap(p[i], p[k]);
//	}
//	sort(p, p + length);
//}
//
//int F(int n)
//{
//	/*if (n == 0)return 1;
//	return F(n - 1) * n;*/
//	if (n == 0 || n == 1)return 1;
//	return F(n - 1) + F(n - 2);
//}

//bool cmp(pair<double, double> a, pair<double, double> b)
//{
//	return a.second > b.second;
//}

//LL bineryPow(LL a, LL b, LL m)
//{
//	if (b == 0)return 1;
//	if (b & 1)return a * bineryPow(a, b - 1, m) % m;
//	else {
//		LL mul = bineryPow(a, b / 2, m);
//		return mul * mul% m;
//	}
//}
//
//LL binaryPow(LL a, LL b, LL m)
//{
//	LL ans = 1;
//	while (b > 0)
//	{
//		if (b & 1)ans = ans * a % m;
//		a = a * a % m;
//		b >>= 1;
//	}
//	return ans;
//}
//
//
//void merge(int A[], int L1, int R1, int L2, int R2)
//{
//	int i = L1, j = L2;
//	int temp[maxn], index = 0;
//	while (i <= R1, j <= R2)
//	{
//		if (A[i] <= A[j])temp[index++] = A[i++];
//		else temp[index++] = A[j++];
//	}
//	while (i <= R1)temp[index++] = A[i++];
//	while (j <= R2)temp[index++] = A[j++];
//	for (int i = 0; i < index; i++) A[L1 + i] = temp[i];
//}
//
//bool check(int mid)
//{
//	//TUDO
//}
//
//int bsearch(int l, int r)
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
//int bsearch2(int l, int r)
//{
//	while (l < r)
//	{
//		int mid = l + r + 1 >> 1;
//		if (check(mid))l = mid;
//		else r = mid - 1;
//	}
//	return l;
//}

int main()
{
	/*int n, maxNeed;
	cin >> n >> maxNeed;
	double kucun[1000], price[1000];
	pair<double,double> danjia[1000];
	double ans = 0.0;
	for (int i = 0; i < n; i++)
	{
		cin >> kucun[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	for (int i = 0; i < n; i++)
	{
		danjia[i].first = kucun[i];
		danjia[i].second = price[i] / kucun[i];
	}
	sort(danjia, danjia + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (danjia[i].first <= maxNeed)maxNeed -= danjia[i].first, ans += danjia[i].second * danjia[i].first;
		else {
			ans += danjia[i].second * maxNeed;
			break;
		}
	}*/
	/*int number[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> number[i];
	}
	for (int i = 1; i < 10; i++)
	{
		if (number[i] > 0)
		{
			cout << i;
			number[i]--;
			break;
		}
	}
	for (int i = 0; i < 10;)
	{
		if (number[i])
		{
			cout << i;
			number[i]--;
			continue;
		}
		i++;
	}*/
	//string str = "";
	//cin >> str;
	//pair<int, int> ans[maxn];
	//int left = 0,right = 0;
	//for (int i = 0; i < str.length(); i++)
	//{
	//	if (str[i] == 'P')ans[left].first += 1;
	//	if (str[i] == 'A' && ans[left].first != 0)left++;
	//}
	//for (int i = 0; i < str.length(); i++)
	//{
	//	if (str[i] == 'T')ans[right].second += 1;
	//	if (str[i] == 'A' && ans[right].second != 0)right++;
	//}
	//int i = 0;
	//int res = 0;
	//while (ans[i].first != 0 && ans[i].second != 0)
	//{
	//	res += ans[i++].first * ans[i].second;
	//}
	//res = res % mod;

	int n = 12 % 10;

}
