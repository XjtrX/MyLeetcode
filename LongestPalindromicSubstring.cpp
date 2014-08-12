/*
author: jtr@BNU
date : 14.8.10
Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

string longestPalindrome(string s) {
	string res;
	if (s.size() < 2)
	{
		return s;
	}
	int count = s.size();
	int maxlen = 0;
	int location = -1;
	vector<bool> odd(count, true);
	vector<bool> even(count,false);

	 for (int i = 0; i < count - 1; ++i)
	 {
	 	if(s[i] == s[i + 1]) even[i] = true;
	 }
	 bool isodd = true;
	 for (int i = 1; i < count; ++i)
	 {
	 	int temmax = 0;
	 	//odd
	 	for (int step = 0; step <= count/2; ++step)
	 	{
	 		if (odd[i])
	 		{
	 			if (i >= step && i+step < count && s[i-step] == s[i+step])
	 			{
	 				temmax = step;
	 			}
	 			else
	 			{
	 				odd[i] = false;
	 				break;
	 			}
	 		}
	 		else
	 		{
	 			break;
	 		}
	 	}
	 	if (temmax > maxlen)
	 	{
	 		maxlen = temmax;
	 		isodd = true;
	 		location = i;
	 	}

	 	//even
	 	temmax = 0;
	 	for (int step = 1; step <= count/2; ++step)
	 	{
	 		if (!even[i])
	 		{
	 			break;
	 		}
	 		else
	 		{
	 			if (i >= step && i+1+step < count && s[i-step] == s[i+1+step])
	 			{
	 				temmax = step;
	 			}
	 			else
	 			{
	 				even[i] = false;
	 				break;
	 			}
	 		}
	 	}
	 	if (temmax >= maxlen)
	 	{
	 		maxlen = temmax;
	 		isodd = false;
	 		location = i;
	 	}
	 }
	
	 if (maxlen == 0)
	 {
	 	for (int i = 0; i < count - 1; ++i)
	 	{
	 		if(s[i] == s[i + 1])
	 		{
	 			res = s.substr(i,2);
	 			return res;
	 		}
	 	}

	 }
	 if (isodd)
	 {
	 	res = s.substr(location - maxlen, 2 * maxlen + 1);
	 }
	 else
	 {
		res = s.substr(location - maxlen, 2 * (maxlen + 1));
	 }

	return res;
}

int main()
{
	string s = "bbsfadfasfcccccccccvsdfasdsaggggggggggavsdfasdccccccccdsadfscdsadafdsafdba";

	cout<<s<<endl<<longestPalindrome(s)<<endl;

	return 0;
}