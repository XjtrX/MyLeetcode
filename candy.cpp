/*
author: jtr@BNU
date: 14.9.8
problem:
Candy Total Accepted: 17439 Total Submissions: 92000 My Submissions
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

#include "myIncs.h"

int candy(vector<int> &ratings)
{
	int res = 0;
	int len = ratings.size();
	if(len == 0) return 0;
	if(len == 1) return 1;
	vector<int> candys(len,1);
	for (int i = 1; i < len; ++i)
	{
		if(ratings[i] > ratings[i - 1])
			candys[i] = candys[i - 1] + 1;
	}
	for (int i = len - 2; i >= 0; --i)
	{
		if(ratings[i] > ratings[i + 1])
			candys[i] = max(candys[i + 1] + 1, candys[i]);
	}
	for (int i = 0; i < len; ++i)
	{
		res += candys[i];
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> ratings = {1,2,2};

	for (int i = 0; i < ratings.size(); ++i)
	{
		cout<<ratings[i]<<", ";
	}
	cout<<endl;
	cout<<candy(ratings)<<endl;
	return 0;
}