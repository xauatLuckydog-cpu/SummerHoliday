// NineTeen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		int n = nums.size();
		vector<string> vec;
		for (int i = 0; i < n; i++)
		{
			vec.push_back(to_string(nums[i]));
		}
		string res;
		sort(vec.begin(), vec.end());
		for (int i = vec.size() - 1; i >= 0; i--)
		{
			res += vec[i];
		}
		return res;

	}
	static bool cmp(int x, int y) {
		string sx = to_string(x), sy = to_string(y);
		return sx + sy > sy + sx;
	}
	string largestNumber2(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		string ans = "";
		for (int i = 0; i < nums.size(); i++)
			ans += to_string(nums[i]);

		for (int i = 0; i < ans.length(); i++)
			if (i == ans.length() - 1 || ans[i] != '0')
				return ans.substr(i, ans.length() - i);
		return ans;
	}
	bool check(const string& s, const string& word) {
		int n = s.length(), m = word.length();
		int i = 0, j = 0;
		while (i < n && j < m) {
			if (s[i] == word[j]) {
				i++;
				j++;
			}
			else
				i++;
		}
		return j == m;
	}
	string findLongestWord(string s, vector<string>& d) {
		string ans = "";
		for (string& word : d) {
			if (check(s, word)) {
				if (ans.length() < word.length())
					ans = word;
				else if (ans.length() == word.length())
					ans = min(ans, word);
			}
		}

		return ans;
	}
	string reorganizeString(string S) {
		vector<char> vec;
		for (auto c : S)vec.push_back(c);
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] == vec[i + 1])
			{
				for (int j = i + 2; j < vec.size(); j++)
				{
					if (vec[i + 1] != vec[j])
					{
						swap(vec[i + 1], vec[j]);
						break;
					}
				}
				if (vec[i] == vec[i + 1])return "";
			}
		}
		string ans;
		for (auto c : vec)ans += c;
		return ans;
	}
	bool cmp1(pair<int, vector<int>> a, pair<int, vector<int>> b)
	{
		return a.first < b.first;
	}
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> res;
		vector<pair<int,vector<int>>> pir;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				pir.push_back({ abs(i - r0) + abs(j - c0) ,{i,j} });
			}
		}
		sort(pir.begin(), pir.end());

		for (int i = 0; i < pir.size(); i++)
		{
			res.push_back(pir[i].second);
		}
		return res;
	}

	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> res,temparr;
		
		for (auto k : arr2)
		{
			for (int i = 0; i < arr1.size(); i++)
			{
				if (arr1[i] == k) {
					res.push_back(arr1[i]);
					arr1[i] = INT_MAX;
				}
			}
		}
		for (auto temp : arr1)if (temp != INT_MAX)temparr.push_back(temp);
		sort(temparr.begin(), temparr.end());
		for (int i = 0; i < temparr.size(); i++)
		{
			res.push_back(temparr[i]);
		}
		return res;
	}
	bool isAnagram(string _s, string _t) {
		vector<char> s, t;
		if (_s.length() != _t.length())return false;
		for (int i = 0; i < _s.length(); i++)
		{
			s.push_back(_s[i]);
			t.push_back(_t[i]);
		}
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		for (int i = 0; i < s.size(); i++)if (s[i] != t[i])return false;
		return true;
	}

};

int main()
{
	Solution test;
	test.allCellsDistOrder(2, 2, 0, 1);
	vector<string> vec;
	vec.push_back("hudapang");
    cout << vec[0][2]; 
}