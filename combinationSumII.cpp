/*
author: jtr@BNU
date: 14.8.20
problem:
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;


void nextCombination(vector<vector<int> > & res,vector<int> tem ,vector<int> &candidates, vector<int>::iterator canItr, int target)
{
	if (target == 0 )
	{
		res.push_back(tem);
		// tem.clear();
		return;
	}
	if (canItr == candidates.end())
	{
		//tem.clear();
		return;
	}
	if (target < *canItr)
	{
		//tem.clear();
		return;
	}

	int i  = 0;
	while(*(canItr + i) == *(canItr + i + 1)) i++;
	nextCombination(res,tem, candidates, canItr + i + 1,target);
	tem.push_back(*canItr);
	nextCombination(res,tem, candidates, canItr + 1, target - *canItr);

}

vector<vector<int> >combinationSum2(vector<int> &candidates , int target)
{
	vector<vector<int> > res;
	if (candidates.size() < 1)
	{
		return res;
	}
	sort(candidates.begin(), candidates.end()); //sort
	//candidates.resize( std::distance(candidates.begin(),unique(candidates.begin(),candidates.end()))); // unique
	std::vector<int> tem;
	nextCombination(res, tem,candidates, candidates.begin(), target);
	//sort(res.begin(), res.end());
	//res.resize(distance(res.begin(), unique(res.begin(), res.end())));
	return res;
}


int main(int argc, char const *argv[])
{
	vector<int > candidates= {1,1,1,2,4,5,6};
	int target = 5;

	for (std::vector<int>::iterator i = candidates.begin(); i != candidates.end(); ++i)
	{
		cout<<*i<<",";
	}
	cout<<endl<<target<<endl;

	vector<vector<int> > res = combinationSum2(candidates, target);

	for (std::vector<std::vector<int> >::iterator itr = res.begin(); itr != res.end(); ++itr)
	{
		for (std::vector<int>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout<<*i<<", ";
		}
		cout<<endl;
	}

	return 0;
}