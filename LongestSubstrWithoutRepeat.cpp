/*
author: jtr@BNU
date: 14.8.8
Longest Substring Without Repeating Characters Total Accepted: 19180 Total Submissions: 86713 My Submissions
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;


int lengthOfLongestSubstring(string s) {
	int len = s.length();
	if(len< 2) return len;

	int maxlen = 0;
	map<char,int> tem; //last adress of the letter
	tem.clear();
	int temmax = 0;
	int i = 0;
	int start = 0; //begin of the substring
	while(i<len){
		//tem.clear();
		while (i<len && tem[s[i]] - 1< start  )
		{
			tem[s[i]] = i + 1;
			temmax++;
			++i;
		}

		maxlen = max(maxlen,temmax);
		if (i<len)
		{
			temmax = i - tem[s[i]] + 1 ;
			start = tem[s[i]];
			tem[s[i]] = i + 1;
			i++;
			if (i == len)
			{
				maxlen = max(maxlen,temmax);
			}
		}
		else
			return maxlen;
	}
	return maxlen;
    }


int main()
{
	string s = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac";
	cout<<s<<endl;
	cout<<lengthOfLongestSubstring(s)<<endl;
	return 0;
}