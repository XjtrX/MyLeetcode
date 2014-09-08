/*
author: jtr@BNU
date: 14.9.8
problem:
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/


#include "myIncs.h"
bool isWordBreak(string &s, vector<bool> & t, unordered_set<string> &dict)
{

}

bool wordBreak(string s, unordered_set<string> & dict)
{
	if(s == "") return true;
	int len = s.size();
	vector<bool> t(len, false);
	string tem;
	for(int i = len - 1; i >= 0; --i)
	{
		tem = s.substr(i);
		if(dict.find(tem) != dict.end())
		{
			t[i] = true;
			continue;
		}
		bool temi = false;
		int ii = 0;
		for (int k = i; k <= len - 1; ++k)
		{
			temi |= (t[k] && (dict.find(s.substr(i, k - i))) != dict.end());
			if(temi)
			{
				t[i] = true;
				break;
			}
		}
	}
	return t[0];
}

int main(int argc, char const *argv[])
{
	string s = "leetcode";

	unordered_set<string> dict = {
		"leet",
		"code"
	};

	cout<<s<<endl;

	for (std::unordered_set<string>::iterator itr = dict.begin(); itr != dict.end(); ++itr)
	{
		cout<<*itr<<",";
	}
	cout<<endl;

	cout<<s<<(wordBreak(s, dict) ? " can " : " can not ")<<"be segmented. "<<endl;
	return 0;
}