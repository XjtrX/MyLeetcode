/*
author: jtr@BNU
date: 14.8.23
problem:
Length of Last Word Total Accepted: 16284 Total Submissions: 55628 My Submissions
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

bool isLetter(char c)
{
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}
int lengthOfLastWord(const char * s)
{
	int res = 0, tem = 0;
	int cur = 0;
	while(s[cur] != '\0') cur++;
	cur--;
	while(cur>=0 && s[cur] == ' ') cur--;
	while(cur>=0 && isLetter(s[cur])) 
	{
		cur--;
		res++;
	}
	if (cur == -1  || s[cur] == ' ')
	{
		return res;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	char s[] = " adss   da1 ";

	cout<<s<<endl<<endl<<lengthOfLastWord(s)<<endl;
	return 0;
}