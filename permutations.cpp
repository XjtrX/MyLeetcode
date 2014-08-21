/*
author: jtr@BNU
date: 14.8.21
problem:
Permutations Total Accepted: 20919 Total Submissions: 66832 My Submissions
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].


*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
using namespace std;


vector<vector<int> > permute(vector<int> & num)
{
	vector<vector<int> > res;
	if (num.size()<2)
	{
		res.push_back(num);
		return res;
	}

	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
	{

		std::vector<int> next = num;
		next.erase(next.begin() + (itr - num.begin()));
		std::vector<std::vector<int> > vres = permute(next);
		for (std::vector<std::vector<int> >::iterator vitr = vres.begin(); vitr != vres.end(); ++vitr)
		{		
			vector<int> tem;
			tem.push_back(*itr);
			for (std::vector<int>::iterator i = vitr->begin(); i != vitr->end(); ++i)
			{
				tem.push_back(*i);
			}
			res.push_back(tem);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> num = {1,2,3,4};

	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
	{
		cout<<*itr<<", ";
	}
	cout<<endl<<"-----"<<endl;

	vector<vector<int> > res = permute(num);
	for (std::vector<vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		for (std::vector<int>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout<<*i<<",";
		}
		cout<<endl;
	}
	return 0;
}