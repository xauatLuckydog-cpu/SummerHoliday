// sad.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 55;
int n ,m;
int w[N][N];
int f[N * 2][N][N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> w[i][j];
	for (int k = 2; k <= n + m; k++)
		for (int i1 = 1; i1 <= n; i1++)
			for (int i2 = 1; i2 <= n; i2++) {
				int j1 = k - i1, j2 = k - i2;
				if (j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m) {
					int t = w[i1][j1];
					if (i1 != i2) t += w[i2][j2];
					int& x = f[k][i1][i2];
					x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
					x = max(x, f[k - 1][i1 - 1][i2] + t);
					x = max(x, f[k - 1][i1][i2 - 1] + t);
					x = max(x, f[k - 1][i1][i2] + t);
				}
			}
	cout << f[n + m][n][n];
	return 0;
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
