#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<int, int> PII;

class Solution {
public:
	vector<int> pre, bac, output;
	vector<int> productExceptSelf(vector<int>& nums) {
		int res = 1;
		for (int i = 0; i < nums.size(); i++) {
			res = res * nums[i];
			pre.push_back(res);
		}
		res = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			res = res * nums[i];
			bac.push_back(res);
		}
		reverse(bac.begin(), bac.end());
		output.push_back(bac[1]);
		for (int i = 1; i < pre.size() - 1; i++) {
			output.push_back(pre[i - 1] * bac[i + 1]);
		}
		output.push_back(pre[pre.size()-2]);
		return output;
	}
};

int main() {
	Solution test;
	vector<int> res = { 1,2,3,4 };
	test.productExceptSelf(res);
}
	/*int n, m;
	cin >> n >> m;
	unordered_map<int, int> AS, BS;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if ((i + j) % 2)AS[x]++;
			else BS[x]++;
		}
	}

	vector<PII>A, B;
	for (auto item : AS) A.push_back({ item.second, item.first });
	for (auto item : BS) B.push_back({ item.second, item.first });
	sort(A.begin(), A.end()), reverse(A.begin(), A.end());
	sort(B.begin(), B.end()), reverse(B.begin(), B.end());


	int res = 0;
	for (int i = 0; i < 2 && i < A.size(); i++) {
		for (int j = 0; j < 2 && j < B.size(); j++) {
			if (A[i].second == B[j].second)res = max(res, max(A[i].first, B[j].first));
			else res = max(res, A[i].first + B[j].first);
		}
	}
	if (A.empty()) res = B[0].first;
	if (B.empty()) res = A[0].first;

	cout << n * m - res << endl;
	return 0;
}*/

//
//const int N = 110;
//int n, m;
//int res[N][N];
//
//int main()
//{
//	cin >> n >> m;
//	int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
//	int x = 0, y = 0, d = 0;
//	for (int i = 1; i <= n * m; i++) {
//		int nx = x + dx[d], ny = y + dy[d];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m || res[nx][ny]) {
//			d = (d + 1) % 4;
//			nx = x + dx[d], ny = y + dy[d];
//		}
//		res[x][y] = i;
//		x = nx, y = ny;
//	}
//    std::cout << "Hello World!\n";
//}
