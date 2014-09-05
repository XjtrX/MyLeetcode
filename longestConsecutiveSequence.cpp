/*
author: jtr@BNU
date: 14.9.5
problem:
Longest Consecutive Sequence Total Accepted: 19001 Total Submissions: 67777 My Submissions
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


#include "myIncs.h"


int longestConsecutive(vector<int> & num)
{
	int res = 0;
	if(num.size() < 2) return (int)num.size();
	map<int, int> m;
	for (int i = 0; i < num.size(); ++i)
	{
		if(m[num[i]] == 0) m[num[i]] = 1;
	}
	int tem = 1;
	for (std::map<int,int>::iterator i = m.begin(); i != m.end(); ++i)
	{
		tem = 1;
		while( i->first + 1 == (++i)->first && i != m.end())
		{
			tem++;
		}
		--i;
		res = max(res, tem);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> num = {100, 4, 200, 1, 3, 2,201,200,199,198,197,196};

	for (std::vector<int>::iterator i = num.begin(); i != num.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;

	cout<<longestConsecutive(num)<<endl;
	return 0;
}