/*
author: jtr@BNU
date: 14.8.22
problem:
Anagrams Total Accepted: 13516 Total Submissions: 57533 My Submissions
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
//the meaning of the problem is so badly.... or my english is so poor.
#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;


vector<string> anagrams(vector<string> & strs)
{
	vector<string> res;
	vector<pair<string,int> > tm;
	for (std::vector<string>::iterator itr = strs.begin(); itr != strs.end(); ++itr)
	{
		string tem = *itr;
		sort(tem.begin(),tem.end());
		tm.push_back(make_pair(tem, itr - strs.begin()));
	}

	sort(tm.begin(),tm.end());

	map<string, int> timesOfStr;
	for (std::vector<pair<string, int> >::iterator itr = tm.begin(); itr != tm.end(); ++itr)
	{
		timesOfStr[itr->first]++;
	}
	for (std::vector<pair<string, int> >::iterator itr = tm.begin(); itr != tm.end(); ++itr)
	{
		if(timesOfStr[itr->first] > 1)
			res.push_back(strs[itr->second]);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	std::vector<string> strs = {
		"date",
		"tade",
		"eatd"
	};
	for (std::vector<string>::iterator itr = strs.begin(); itr != strs.end(); ++itr)
	{
		cout<<*itr<<endl;
	}
	cout<<"--------------------"<<endl;
	vector<string> res = anagrams(strs);
	for (std::vector<string>::iterator i = res.begin(); i != res.end(); ++i)
	{
		cout<<*i<<endl;
	}
	return 0;
}