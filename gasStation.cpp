/*
author: jtr@BNU
date: 14.9.8
problem:
Gas Station Total Accepted: 19251 Total Submissions: 74956 My Submissions
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
#include "myIncs.h"


int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
	int len = gas.size();
	if(len == 0) return -1;
	if(len == 1) return gas[0] >= cost[0] ? 0 : -1;
	map<int, pair<int,int> > M;
	int res = 0;
	int curRest = 0;
	for (int i = 0; i < len; ++i)
	{
		curRest = gas[i] - cost[i];
		if(curRest < 0)
		{
			M[i] = {(i + 1)%len, curRest};
			// cout<<i<<", "<<(i + 1)%len<<", PL"<<curRest<<endl;
			continue;
		}
		int j = (i + 1)%len;
		for (; j != i; )
		{
			if(j > i)
			{
				curRest = curRest + gas[j] - cost[j];
				// cout<<i<<","<<j<<","<<curRest<<"P"<<endl;
				if(curRest < 0)
				{
					M[i] = {(j + 1) % len, curRest};
					break;
				}
				j = (1 + j)%len;
			}
			else
			{
				curRest += M[j].second;
				j = M[j].first;
				// cout<<i<<", "<<j<<","<<curRest<<"H"<<endl;
				if(curRest < 0)
				{
					M[i] = {j, curRest};
					break;
				}
				if(j >= i && curRest >= 0)
					return i;
				else if (j >= i && curRest < 0)
				{
					return -1;
				}
			}
		}
		if(j >= i && curRest >= 0)
			return i;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	vector<int> gas = {1,2,3,3};
	vector<int> cost = {2,1,5,1};

	for (std::vector<int >::iterator i = gas.begin(); i != gas.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;
	for (std::vector<int>::iterator i = cost.begin(); i != cost.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;
	cout<<canCompleteCircuit(gas, cost)<<endl;
	return 0;
}