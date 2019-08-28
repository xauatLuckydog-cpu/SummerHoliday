// Thirty.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
public:
	vector<int> father;
	UnionFind(int num) {//num表示元素个数
		for (int i = 0; i < num; i++) {
			father.push_back(i);
		}
	}
	int Find(int n) {
		//非递归
		while (father[n] != n) {
			n = father[n];
		}
		return n;
	}
	int Find_digui(int n) {
		if (father[n] == n)
			return n;
		father[n] = Find_digui(father[n]);//路径压缩
		return father[n];
	}
	void Union(int a, int b) {
		int fa = Find(a);
		int fb = Find(b);
		father[fb] = fa;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}