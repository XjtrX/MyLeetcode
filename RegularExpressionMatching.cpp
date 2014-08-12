/*
author: jtr@BNU
date: 14.8.11
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

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

bool isMatch(const char *s, const char *p) {
	bool res = true;
	int scur = 0, pcur = 0;
	int stemlen = 0, ptemlen = 0;
	char spre , ppre ;
	spre = s[scur];
	ppre = p[pcur];
	//if (spre == ppre || ppre == '.')
	//{
	//	scur++;
	//	pcur++;
	//}
	//else
	//	return false;

	while(s[scur] != '\0' && p[pcur] != '\0')
	{
		if (s[scur] == p[pcur] || p[pcur] == '.')
		{
			//if (s[scur + 1] == '\0' && p[pcur + 1] == '\0') return true;
			stemlen = 0;
			while(s[scur + stemlen + 1] != '\0' && s[scur] == s[scur + stemlen + 1]) stemlen++;
			ptemlen = 0;
			while(p[pcur + ptemlen + 1] != '\0' && s[scur] == p[pcur + ptemlen + 1]) ptemlen++;

			bool isstar = false;
			if (p[pcur + ptemlen + 1] == '*')
			{
				isstar = true;
				while(s[scur] == p[pcur + ptemlen + 1] ) ptemlen++;
			}
			spre = s[scur];
			ppre = p[pcur];

			if (isstar && ptemlen <= 1+ stemlen)
			{
				scur += stemlen + 1;
				pcur = ptemlen + 2 + pcur;
				continue;
			}
			else if (isstar && ptemlen > 1+ stemlen)
				return false;
			if (!isstar && stemlen >= ptemlen)
			{
				scur = scur + 1 +ptemlen;
				pcur = pcur + 1 +ptemlen;
				continue;
			}
			else if (!isstar && stemlen < ptemlen)
			{
				return false;
			}
			continue;
		}
		switch(p[pcur])
		{
			case '.':
				//spre = s[scur];
				//ppre = p[pcur];
				//scur++;
				//pcur++;
				break;
			case '*':
				stemlen = 0;
				ptemlen = 0;
				while( s[stemlen + scur + 1] != '\0' && spre == s[scur + stemlen]) stemlen++;
				while( p[ptemlen + pcur + 1] != '\0' && spre == p[ptemlen + pcur + 1]) ptemlen++;
				if (stemlen + 1 >= ptemlen)
				{
					scur = scur + stemlen ;
					pcur = pcur + ptemlen + 1;
				}
				else if (stemlen < ptemlen)
				{
					return false;
				}
				break;
			default:
				break;
		}
		if (s[scur] != p[pcur])
		{
			return false;
		}
	}
	if (s[scur] != '\0' || p[pcur] != '\0')
	{
		return false;
	}
	return true;
 }

 int main()
 {
 	char s[] = "ab";
 	char p[] = ".*";
 	
 	cout<<"s = "<<s<<endl;
 	cout<<"p = "<<p<<endl;

 	cout<<"s and p are "<<(isMatch(s,p)?"match":"not match")<<endl;
 	return 0;
 }