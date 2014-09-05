/*
author: jtr@BNU
date: 14.9.5
problem:
Valid Palindrome Total Accepted: 18899 Total Submissions: 82496 My Submissions
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

#include "myIncs.h"
#include <cctype>
bool isPalindrome(string s)
{
	int len = s.size();
	if(len < 2) return true;
	int front = 0, back = len - 1;
	char f, b;
	while(front < back)
	{
		f = tolower(s[front]);
		while(front < back && (f - 'a' < 0 || f - 'a' > 25) && (f - '0' < 0 || f - '0' > 9))
		{
			front++;
			f = tolower(s[front]);
		}

		b = tolower(s[back]);
		while(front < back && (b - 'a' < 0 || b - 'a' > 25) && (b - '0' < 0 || b - '0' > 9))
		{
			back--;
			b = tolower(s[back]);
		}
		if(front >= back) return true;
		if(f == b)
		{
			front++;back--;
		}
		else
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s = "ab2a";

	cout<<"\""<<s<<"\""<<(isPalindrome(s)? " is " : " is not ")<<"a palindrome."<<endl;
	return 0;
}