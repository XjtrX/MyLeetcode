/*
author: jtr@BNU
date: 14.8.25
problem:
Simplify Path Total Accepted: 10720 Total Submissions: 53953 My Submissions
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

string simplifyPath(string path)
{
	string res;
	stack<string> S;
	string tem;
	int len = path.size();
	int i = 0;
	while(i < len)
	{
		tem.clear();
		while(path[i] != '/' && i<len)
		{
			tem.push_back(path[i++]);
		}
		
		if(i < len)
			tem.push_back('/');
		//cout<<tem<<endl;
		i++;
		if ("./" == tem || "." == tem)
		{
			if (S.empty())
			{
				S.push("/");
			}
			continue;
		}
		else if ("../"  == tem || ".." == tem)
		{
			if (S.empty())
			{
				S.push("/");
			}
			else if (S.size() > 1)
			{
				S.pop();
			}
		}
		else if ("/" == tem)
		{
			if (S.empty())
			{
				S.push("/");
			}
		}
		else
		{
			S.push(tem);
		}
	}
	while(!S.empty())
	{
		string s = S.top();
		S.pop();
		res = s.append(res);
	}
	if (res.size() > 1 && res.back() == '/')
	{
		res.pop_back();
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string path = "/../";
	cout<<path<<endl;
	cout<<simplifyPath(path)<<endl;
	return 0;
}