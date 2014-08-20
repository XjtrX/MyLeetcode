/*
author: jtr@BNU
date: 14.8.20
problem:
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;
string nextStr(string s)
{
	if (s.size() < 1)
	{
		return "";
	}
	string res, ss;
	size_t len = s.size();
	size_t cur = 0;
	size_t tem = 0;
	char pre = s[0];
	cur++;
	tem++;
	while(cur < len)
	{
		if (s[cur] != pre)
		{
			ss.clear();
			while(tem)
			{
				ss.insert(ss.begin(),tem%10 + '0');
				tem /= 10;
			}
			res.append(ss);
			res.insert(res.end(),pre);
			tem = 1;
			pre = s[cur];
			cur++;
		}
		else
		{
			cur++;
			tem++;
		}
	}
	ss.clear();
	while(tem)
	{
		ss.insert(ss.begin(),tem%10 + '0');
		tem /= 10;
	}
	res.append(ss);
	res.insert(res.end(), pre);
	return res;
}

string countAndSay(int n)
{
 	string res = "1";
 	if (n < 1) return "";
 	// int i = 0;
 	while(--n) 
 	{
 		// cout<<i++<<": "<<res<<endl;
 		res = nextStr(res);
 	}
 	// cout<<i++<<": "<<res<<endl;
 	return res;
}

int main(int argc, char const *argv[])
{
	int n = 8;

	cout<<n <<endl;

	cout<<countAndSay(n)<<endl;
	return 0;
}