/*
author: jtr@BNU
date: 14.8.19
problem:
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

int longestValidParentheses(string s)
{
	int res = 0;
	if (s.size() < 2)
	{
		return 0;
	}
	stack<char> p;
	stack <int> q;
	int cur = 0;
	int tem = 0;
	int len = s.size();
	while(cur<len && s[cur] == ')') cur++;
	if (cur < len)
	{
		p.push(s[cur]);
		q.push(0);
		cur++;
	}
	while(cur < len)
	{
		if (s[cur] == ')' && !p.empty() && !q.empty() && p.top() == '(')
		{
			tem = 2;
			p.pop();
			while(!q.empty() && q.top() != 0 && q.top() != -1)
			{
				tem += q.top();
				q.pop();
			}
			if (q.top() == 0)
			{
				q.pop();
			}
			while(!q.empty() && q.top() != 0 && q.top() != -1)
			{
				tem += q.top();
				q.pop();
			}
			q.push(tem);
			res = max(res,tem);
		}
		else if (s[cur] == ')')
		{
			p.push(')');
			q.push(-1);
		}
		else if (s[cur] == '(')
		{
			p.push('(');
			q.push(0);
		}
		cur++;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string  s = "(()))((())))())()";
	cout<<s<<endl<<longestValidParentheses(s)<<endl;
	return 0;
}