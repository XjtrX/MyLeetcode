/*
author: jtr@BNU
date: 14.8.21
problem:
Permutations II Total Accepted: 14532 Total Submissions: 58312 My Submissions
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

//TLM
// vector<vector<int> > permuteUnique(vector<int> & num)
// {
// 	sort(num.begin(), num.end());
// 	vector<vector<int> > res;
// 	if (num.size()<2)
// 	{
// 		res.push_back(num);
// 		return res;
// 	}

// 	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
// 	{
// 		std::vector<int> next = num;
// 		next.erase(next.begin() + (itr - num.begin()));
// 		std::vector<std::vector<int> > vres = permuteUnique(next);
// 		for (std::vector<std::vector<int> >::iterator vitr = vres.begin(); vitr != vres.end(); ++vitr)
// 		{
// 			vector<int> tem;
// 			tem.push_back(*itr);
// 			for (std::vector<int>::iterator i = vitr->begin(); i != vitr->end(); ++i)
// 			{
// 				tem.push_back(*i);
// 			}
// 			res.push_back(tem);
// 		}
// 	}
// 	sort(res.begin(),res.end());
// 	res.resize(distance(res.begin(),unique(res.begin(),res.end())));
// 	return res;
// }


//Treat the vector as a  complete graph, and then set every node as the start, and then to find all the path of the graph. 
//All the path will construct the result of the permute of the vector.
//DFS
void DFS(map<int,int> gmap, vector<vector<int> > & res, vector<int> &path,size_t len)
{
	if (path.size() == len)
	{ 
		res.push_back(path);
		return;
	}
	for(map<int,int>::iterator itr = gmap.begin(); itr != gmap.end(); ++itr)
	{
		int count = 0;
		for (std::vector<int>::iterator i = path.begin(); i != path.end(); ++i)
		{
			if(*i == itr->first) count++;
		}
		if(itr->second > count)
		{
			path.push_back(itr->first);
			DFS(gmap, res, path, len);
			path.pop_back();
		}
	}
}
vector<vector<int> > permuteUnique(vector<int> & num)
{
	// sort(num.begin(), num.end());
	//count the times of each node of the graph
	map<int,int> timesOfEachNode;
	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
	{
		timesOfEachNode[*itr]++;
	}

	vector<vector<int> > res;
	vector<int> path;
	DFS(timesOfEachNode, res, path, num.size());
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> num = {1,2,3};

	for (std::vector<int>::iterator itr = num.begin(); itr != num.end(); ++itr)
	{
		cout<<*itr<<", ";
	}
	cout<<endl<<"-----"<<endl;

	vector<vector<int> > res = permuteUnique(num);
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