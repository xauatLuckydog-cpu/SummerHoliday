#include <iostream>
#include <map>
#include<string>
using namespace std;

class Solution 
{ 
public: 
	string defangIPaddr(string address) 
	{ 
		char* p; 
		p = new char[address.size() + 7]; 
		int j = 0; 
		for (int i = 0; i < address.size(); i++) 
		{ 
			if (address[i] == '.') 
			{ 
				p[j] = '['; 
				p[j + 1] = '.'; 
				p[j + 2] = ']'; 
				j = j + 3; } 
			else 
			{ 
				p[j] = address[i]; j++; 
			} 
		} 
		p[j] = '\0'; 
		string result; 
		result = p; 
		delete[] p; 
		return result; 
	} 
};


int main()
{
	string address = "1.1.1.1";

	//string line = "this@ is@ a test string!";
	//line = line.replace(line.begin(), line.begin() + 6, "");	//用str替换从begin位置开始的6个字符
	//cout << line << endl;
	//return 0;
	
}