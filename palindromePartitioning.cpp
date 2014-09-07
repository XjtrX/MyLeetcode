/*
author: jtr@BNU
date: 14.9.6
problem:
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

#include "myIncs.h"

vector<vector<string> > partition(string s)
{
	int len = s.size();
	vector<vector<string> > res;
	if(len < 1) return res;
	vector<string> tem;
	if(len == 1) 
	{
		tem.push_back(s);
		res.push_back(tem);
		return res;
	}

	string s1;
	vector<vector<string> > restem;
	int cur = 0;
	while(cur <= len/2)
	{
		int t = 0;
		while(cur - t >= 0 && s[cur - t] == s[cur + t]) t++;
		t--;
		if(cur - t == 0)
		{
			if(cur + t == len - 1)
			{
				tem.clear();
				tem.push_back(s);
				res.push_back(tem);
			}
			else
			{
				s1 = s.substr(cur + t + 1);
				restem = partition(s1);
				for (std::vector<vector<string> >::iterator itr = restem.begin(); itr != restem.end(); ++itr)
				{
					tem.clear();
					tem.push_back(s.substr(0,2*t + 1));
					for (std::vector<string>::iterator i = itr->begin(); i != itr->end(); ++i)
					{
						tem.push_back(*i);
					}
					res.push_back(tem);
				}
			}

		}

		t = 0;
		while(cur - t >= 0 && s[cur - t] == s[cur + t + 1]) t++;
		t--;
		if(cur - t == 0)
		{
			if(cur + t + 1 == len - 1)
			{
				tem.clear();
				tem.push_back(s);
				res.push_back(tem);
			}
			else
			{
				s1 = s.substr(cur + t + 2);
				restem = partition(s1);
				for (std::vector<vector<string> >::iterator itr = restem.begin(); itr != restem.end(); ++itr)
				{
					tem.clear();
					tem.push_back(s.substr(0,2*t + 2));
					for (std::vector<string>::iterator i = itr->begin(); i != itr->end(); ++i)
					{
						tem.push_back(*i);
					}
					res.push_back(tem);
				}
			}

		}
		cur++;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string s = "bbabb";

	cout<<s<<endl;

	vector<vector<string> > res = partition(s);

	for (std::vector<vector<string> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		for (std::vector<string>::iterator i = itr->begin(); i != itr->end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}
	return 0;
}