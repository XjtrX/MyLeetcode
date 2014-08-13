/*
author: jtr@BNU
date: 14.8.13
problem:
Valid Parentheses Total Accepted: 15994 Total Submissions: 56689 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;

bool isValid(string s)
{
	bool res = true;
	if (s.size()<2)
	{
		return false;
	}
	map<char,char> mp;
	mp['('] = ')';
	mp['{'] = '}';
	mp['['] = ']';
	stack<char> St;
	int len = s.size();
	int k = 0;
	do{
		if (s[k] == '(' || s[k] == '{' || s[k] == '[')
		{
			St.push(s[k]);
			k++;
		}
		else
		{
			if (!St.empty() && s[k] == mp[St.top()])
			{
				k++;
				St.pop();
			}
			else
			{
				return false;
			}
		}

	}while(k < len || !St.empty());
	return res;
}

int main()
{
	string s = "()[]{}{";

	cout<<"\""<<s<<"\""<<(isValid(s)?" is Valid.":" is not valid.")<<endl;

	return 0;
}