/*
author: jtr@BNU
date: 14.8.21
problem:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
using namespace std;

//TLM  .......

// bool isMatch(const char * s, const char * p)
// {
	
// 	while(*s != '\0' && *p != '\0')
// 	{
// 		cout<<"Here! "<<s<<", "<<p<<endl;
// 		if (*s == *p || *p == '?') 
// 		{
// 			s++;p++;
// 		}
// 		if (*p == '*')
// 		{
// 			while(*p == '*' || *p == '?') p++;
// 			if (*p == '\0')
// 			{
// 				return true;
// 			}

// 			while(*s != '\0')
// 			{
// 				while(*s != '\0' && *s != *p) s++;
// 				if (isMatch( ++s,p + 1))
// 				{
// 					return true;
// 				}
// 			}
// 			return false;
// 		}
// 		if (*s != *p)
// 		{
// 			return false;
// 		}
// 	}
// 	if (*s != '\0')
// 	{
// 		return false;
// 	}
// 	while(*p != '\0' && *p == '*')p++;
// 	if (*p != '\0')
// 	 {
// 	 	return false;
// 	 } 
// 	return true;
// }

//no 
bool isMatch(const char * s, const char * p)
{
	bool flag = false;
	const char * pstr;
	const char * sstr;
	while(*s != '\0')
	{

		//cout<<"Here! "<<s<<", "<<p<<endl;

		if (*s == *p || *p == '?')
		{
			s++;p++;
		}
		else if (*p == '*')
		{
			flag = true;
			pstr = p;
			sstr = s;
			while(*pstr == '*') pstr++;
			if (*pstr == '\0')
			{
				return true;
			}
			p = pstr;
		}
		else if (*s != *p )
		{
			if(!flag) return false;
			sstr++;
			s = sstr;
			p = pstr;
		}
	}
	if (*s != '\0')
	{
		return false;
	}
	while(*p != '\0' && *p == '*')p++;
	if (*p != '\0')
	 {
	 	return false;
	 }
	return true;
}


//copy github 
// bool isMatch(const char *s, const char *p) {
// 	bool star = false;
// 	const char *str, *ptr;
// 	for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
// 		cout<<str<<", "<<ptr<<endl;
// 		switch (*ptr) {
// 			case '?':
// 				break;
// 			case '*':
// 				star = true;
// 				s = str, p = ptr;
// 				while (*p == '*') p++; //skip continuous '*'
// 				if (*p == '\0') return true;
// 				str = s - 1;
// 				ptr = p - 1;
// 				break;
// 			default:
// 				if (*str != *ptr) {
// 				// 如果前面没有'*',则匹配不成功
// 				if (!star) return false;
// 				s++;
// 				str = s - 1;
// 				ptr = p - 1;
// 				}
// 		}
// 	}
// 	while (*ptr == '*') ptr++;
// 	return (*ptr == '\0');
// }

int main(int argc, char const *argv[])
{
	const char * s = "adadadadadadaadad";
	const char * p = "*ad";
	cout<<s<<" and "<<p<<" is "<<(isMatch(s,p) ? "match." : "not match.")<<endl;
	return 0;
}