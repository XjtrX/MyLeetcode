/*
author: jtr@BNU
date: 14.8.12
problem:
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

//using recursive to solve the problem

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

bool isMatch(const char *s, const char *p) {
	if (s[0] == '\0' && p[0] == '\0') return true;
	if (p[0] == '\0' && s[0] != '\0')
	{
		return false;
	}
	if (p[1] != '*')
	{
		if (s[0] == p[0] || (p[0] == '.' && s[0] != '\0'))
		{
			return isMatch(s+1, p + 1);
		}
		else
			return false;
	}
	else
	{
		while(s[0] == p[0] || (p[0] == '.' && s[0] != '\0'))
		{
			if (isMatch(s, p+2))
			{
				return true;
			}
			s++;
		}
		return isMatch(s, p+2);
	}
 }

 int main()
 {
 	char s[] = "b";
 	char p[] = "";
 	
 	cout<<"s = "<<s<<endl;
 	cout<<"p = "<<p<<endl;

 	cout<<"s and p are "<<(isMatch(s,p)?"match":"not match")<<endl;
 	return 0;
 }