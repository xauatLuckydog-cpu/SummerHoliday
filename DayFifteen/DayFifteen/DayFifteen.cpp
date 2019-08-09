#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

	int gcd(int a, int b) {
		return !b ? a : gcd(b, a % b);
	}

	void B1019(int x)
	{
		int nums[4] = { 0 };
		string str = to_string(x);
		for (int i = 0; i < str.length(); i++)
		{
			nums[i] = str[i] - 48;
		}
		sort(nums, nums + 4);
		int a = nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];
		int b = nums[0] + nums[1] * 10 + nums[2] * 100 + nums[3] * 1000;
		if (a - b == 0) {
			cout << x << '-' << x << '=' << x - x;
			return;
		}
		int ans = b - a;
		//cout << b << '-' << a << '=' << ans << endl;
		printf_s("%04d - %04d = %04d\n", b, a, ans);
		if (ans == 6174)return;
		B1019(ans);

	}

	/*int reverse3(int x) {
		long rev = 0;
		while (x != 0) {
			if (x > INT_MAX || x < INT_MIN)return 0;
			rev = rev * 10 + x % 10;
			x = x / 10;
		}
		if (rev > INT_MAX || rev < INT_MIN)return 0;
		return rev;
	}

	int reverse(int x) {
		bool is_minus = false;
		long long ans = 0, temp;
		if (x <= 0) x = abs(x), is_minus = true;
		for (;;)
		{
			ans = (ans * 10 + x % 10) > INT_MAX ? 0: ans * 10 + x % 10;
			if (x / 10 == 0)break;
			x = x / 10;
		}
		if (is_minus)ans = -ans;
		return ans;
	}
	int reverse2(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}*/

	int solve(vector<int> nums) {
		int n = nums.size();
		int tot = 0;
		for (int i = 2; i < n; i++) {
			if (nums[i - 2] < nums[i - 1] && nums[i - 1] <= nums[i]) {
				tot += nums[i] - nums[i - 1] + 1;
				nums[i] = nums[i - 1] - 1;
			}
			if (nums[i - 2] > nums[i - 1] && nums[i - 1] >= nums[i]) {
				tot += nums[i - 1] - nums[i] + 1;
				nums[i - 1] = nums[i] - 1;
			}
		}
		return tot;
	}

	int movesToMakeZigzag(vector<int>& nums) {
		int n = nums.size(), ans1, ans2;
		if (n == 1)
			return 0;
		int t0 = nums[0], t1 = nums[1];

		nums[1] = nums[0] <= nums[1] ? nums[0] - 1 : nums[1];
		ans1 = solve(nums) + t1 - nums[1];
		nums[1] = t1;

		nums[0] = nums[0] >= nums[1] ? nums[1] - 1 : nums[0];
		ans2 = solve(nums) + t0 - nums[0];

		return min(ans1, ans2);
	}
};

int main()
{
	Solution test;
	test.B1019(1200);
}