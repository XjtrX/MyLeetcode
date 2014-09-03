/*
author: jtr@BNU
date: 14.9.3
problem:
Scramble String Total Accepted: 12121 Total Submissions: 53667 My Submissions
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool isScramble(string s1, string s2)
{
	if(s1.size() != s2.size()) return false;
	if (s1 == s2 ) return true;
	if (s1.size() == 1 && s1[0] != s2[0]) return false;
	if (s1.size() == 2)
	{
		if(s1[0] == s2[1] && s1[1] == s2[0]) return true;
		return false;
	}

	string tem1 = s1, tem2 = s2;
	sort(tem1.begin(),tem1.end());
	sort(tem2.begin(),tem2.end());
	if (tem1 != tem2) return false;

	int len = s1.size();
	bool res = false;
	for (int i = 1; i < len; ++i)
	{
		res = (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i, len - i), s2.substr(i, len - i)));
		if (res) return true;
		res = (isScramble(s1.substr(0,i), s2.substr(len - i, i))) && isScramble(s1.substr(i, len - i), s2.substr(0,len - i));
		if (res) return true;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	string s1 = "abc";
	string s2 = "bca";

	cout<<s1<<" and "<<s2<< " are "<<(isScramble(s1, s2)? " scramble." : " not scramble.")<<endl;
	return 0;
}