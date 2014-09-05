/*
author: jtr@BNU
date: 14.9.4
problem:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


*/
#include "myIncs.h"


int maxProfit(vector<int> &prices) 
{
	int res = 0;
	if(prices.size() < 2) return 0;
	int len = prices.size();
	vector<int> front(len, 0), b(len + 1, 0);
	int frontLow = 0, bLow = len - 1;
	for (int i = 1; i < len; ++i)
	{
		front[i] = max((prices[i] - prices[frontLow] >= 0 ? prices[i] - prices[frontLow] : 0), front[ i - 1]);
		if(prices[i] < prices[frontLow]) frontLow = i;

		b[len - i - 1] = max((prices[bLow] - prices[len - i - 1] > 0 ? prices[bLow] - prices[len - i - 1] : 0), b[len - i]);
		if(prices[len -i - 1] > prices[bLow]) bLow = len - i - 1;
	}
	for (int i = 1; i < len; ++i)
	{
		// cout<<front[i]<< ", "<< b[i + 1]<<endl;
		res = max(res, front[i] + b[i + 1]);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> prices = {3,2,6,5,0,3};

	for (std::vector<int>::iterator i = prices.begin(); i != prices.end(); ++i)
	{
		cout<<*i<<", ";
	}
	cout<<endl;
	cout<<maxProfit(prices)<<endl;
	return 0;
}