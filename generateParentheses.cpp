/*
author: jtr@BNU
date: 14.8.13
problem:
Generate Parentheses Total Accepted: 17239 Total Submissions: 54975 My Submissions
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> generateParenthesis(int n)
{
	vector<string> res;
	if (n<1)
	{
		string s;
		res.push_back(s);
		return res;
	}
	if (n == 1)
	{
		string s = "()";
		res.push_back(s);
		return res;
	}
	vector<string> tem = generateParenthesis(n-1);
	for (std::vector<string>::iterator i = tem.begin(); i != tem.end(); ++i)
	{
		string ss = *i;
		res.push_back("()"+ *i);
		for (int k = 0; k < ss.size(); ++k)
		{
			if (ss[k] == ')')
			{
				while(k<ss.size() && ss[k] == ')') k++;
				string str = ss;
				str.insert(k,")");
				res.push_back("("+ str);
			}
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

int main()
{
	int n  = 7;

	cout<<n<<endl<<"-------------------"<<endl;
	vector<string> v = generateParenthesis(n);
	int k = 0;
	for (std::vector<string>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout<<++k<<": "<<*i<<", "<<endl;
	}
	return 0;
}