// DayFourteen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> hash;
		for (auto str : strs)
		{
			string key = str;
			sort(key.begin(), key.end());
			hash[key].push_back(str);
		}

		vector<vector<string>> res;
		for (auto item : hash) res.push_back(item.second);
		return res;
	}
	string reverseWords(string s) {
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			while (i < s.size() && s[i] == ' ')i++;
			if (i == s.size())break;
			int j = i;
			while (j < s.size() && s[j] != ' ')j++;
			reverse(s.begin() + i, s.begin() + j);
			if (k)s[k++] = ' ';
			while (i < j)s[k++] = s[i++];
		}
		s.erase(s.begin() + k, s.end());
		reverse(s.begin(), s.end());
		return s;
	}
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> hash;
		for (auto email : emails)
		{
			int at = email.find('@');
			string name;
			for (auto c : email.substr(0, at))
				if (c == '+') break;
				else if (c != '.') name += c;
			string domain = email.substr(at + 1);
			hash.insert(name + '@' + domain);
		}
		return hash.size();
	}

	string longestPalindrome(string s) {
		string res;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i, k = i; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
				if (res.size() < k - j + 1)
					res = s.substr(j, k - j + 1);
			for (int j = i, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
				if (res.size() < k - j + 1)
					res = s.substr(j, k - j + 1);
		}
		return res;
	}

	struct Node
	{
		bool is_end;
		Node* son[26];
		Node() {
			is_end = false;
			for (int i = 0; i < 26; i++)son[i] = NULL;
		}
	}*root;

};

class Trie {//Trie 树的简单实现
public:

	struct Node
	{
		bool is_end;
		Node* son[26];
		Node() {
			is_end = false;
			for (int i = 0; i < 26; i++)son[i] = NULL;
		}
	}*root;

	/** Initialize your data structure here. */
	Trie() {
		root = new Node();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		auto p = root;
		for (auto c : word)
		{
			int u = c - 'a';
			if (p->son[u] == NULL) p->son[u] = new Node();
			p = p->son[u];
		}
		p->is_end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		auto p = root;
		for (auto c : word)
		{
			int u = c - 'a';
			if (p->son[u] == NULL) return false;
			p = p->son[u];
		}
		return p->is_end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		auto p = root;
		for (auto c : prefix)
		{
			int u = c - 'a';
			if (p->son[u] == NULL) return false;
			p = p->son[u];
		}
		return true;
	}
};


int main()
{
	string str = "the sky is blue!";
	Solution test;
	test.reverseWords(str);
}