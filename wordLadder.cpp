/*
author: jtr@BNU
date: 14.9.5
problem:
Word Ladder Total Accepted: 16990 Total Submissions: 93236 My Submissions
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include "myIncs.h"

bool isConnect(string s, string t)
{
	if(s.size() != t.size()) return false;
	int cur = 0, len = s.size();
	int n = 0;
	while(cur < len)
	{
		n += s[cur] == t[cur] ? 0 : 1;
		if (n > 1) 
		{

			return false;
		}
		cur++;
	}
	return true;
}


int ladderLength(string start, string end, unordered_set<string> & dict)
{
	if(start.size() != end.size()) return 0;

	if(isConnect(start, end)) return 2;

	int res = 0;
	string tem = "";
	queue<string> Q, P;
	Q.push(start);
	while(!Q.empty())
	{
		res++;
		while(!Q.empty())
		{
			tem = Q.front();
			Q.pop();
			if(isConnect(tem, end))
			{
				res++;
				return res;
			}
			for (int i = 0; i < tem.size(); ++i)
			{
				char c = tem[i];
				for (int j = 0; j < 26; ++j)
				{
					tem[i] = 'a' + j;
					unordered_set<string>::iterator itr = dict.find(tem);
					if(itr != dict.end())
					{
						P.push(tem);
						dict.erase(itr);
					}
				}
				tem[i] = c;
			}

		}
		while(!P.empty())
		{
			Q.push(P.front());
			P.pop();
		}
	}
	return 0;
}

/*
int ladderLength(string start, string end, unordered_set<string> & dict)
{
	if(start.size() != end.size()) return 0;
	if(isConnect(start, end)) return 2;

	int res = dict.size() + 3;
	for (std::unordered_set<string>::iterator itr = dict.begin(); itr != dict.end(); ++itr)
	{
		if(isConnect(start, *itr))
		{
			unordered_set<string> tem = dict;
			tem.erase(*itr);
			int t = ladderLength(*itr, end, tem);
			if(t != 0) res = min(res, 1 + t);
		}
	}
	if(res == dict.size() + 3) return 0;
	return res;
}
*/
int main(int argc, char const *argv[])
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot","cog","dot","dog","hit","lot","log"};
	cout<<start <<endl <<end<<endl;
	for (std::unordered_set<string>::iterator i = dict.begin(); i != dict.end(); ++i)
	{
		cout<<*i<<",";
	}
	cout<<endl;

	cout<<ladderLength(start, end, dict)<<endl;
	return 0;
}